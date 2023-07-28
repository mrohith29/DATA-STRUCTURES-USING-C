#include<stdio.h>
#define MAX 10
int graph[MAX][MAX] = {0,0};

void Add_Graph(int s,int e,int type)
{
    graph[s][e] = 1;
    if (type == 2)
    {
        graph[e][s] = 1;
    }
}


void printgraph(int v, int type)
{
    if(type == 1)
    printf("Adjacency Matrix for Directed Graph is\n");
    else
    {
        printf("Adjacency Matrix for Undirected Graph is\n");
    }
    for (int i = 1; i <= v; i++)
    {
        printf("VERTEX %d : ",i);
        for (int j = 0; j <= v; j++)
        {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
    
}

int main()
{
    int graph_type;
    printf("Enter (1) if directed graph (2) for undirected graph\n");
    scanf("%d",&graph_type);

    int vertices, edges;
    scanf("%d %d",&vertices,&edges);

    int start, end;
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d",&start, &end);
        Add_Graph(start, end, graph_type);
    }
    printgraph(vertices, graph_type);
}