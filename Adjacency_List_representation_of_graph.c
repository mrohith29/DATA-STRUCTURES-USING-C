#include <stdio.h>
#include <stdlib.h>

struct node
{
    int vertex;
    struct node *next;
};
struct Graph
{
    int numVertices;
    struct node **adjLists;
};

struct node *createNode(int v)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->vertex = v;
    newnode->next = NULL;
    return newnode;
}

struct Graph *createAGraph(int vertices)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct node *));
    int i;
    for (i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph *graph, int s, int d)
{
    struct node *newnode = createNode(d);
    newnode->next = graph->adjLists[s];
    graph->adjLists[s] = newnode;

    newnode = createNode(s);
    newnode->next = graph->adjLists[d];
    graph->adjLists[d] = newnode;
}

void printgraph(struct Graph *graph)
{
    int v;
    printf("ADJACENCY LIST OF GRAPH G IS\n");
    for (v = 0; v < graph->numVertices; v++)
    {
        struct node *temp = graph->adjLists[v];
        printf("Vertex %d : ", v);
        while (temp)
        {
            printf("%d->", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    struct Graph *graph;
    int no_of_edges, no_of_vertices, start, end;
    printf("Enter the number of vertices in the tree\n");
    scanf("%d", &no_of_vertices);

    graph = createAGraph(no_of_vertices);

    printf("Enter the number of edges in the tree\n");
    scanf("%d", &no_of_edges);

    for (int i = 0; i < no_of_edges; i++)
    {
        printf("Enter the starting and ending of the node\n");
        scanf("%d %d", &start, &end);
        addEdge(graph, start, end);
    }
    printgraph(graph);
    return 0;
}
