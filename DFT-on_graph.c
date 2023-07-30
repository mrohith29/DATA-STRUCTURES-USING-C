#include<stdio.h>

#define max 10
int visited[max] = {0};

int G[max][max];
int n;
 
void getgraph()
{
    int i, j;
    for ( i = 1; i <= n; i++)
    {
        for ( j = 1; j <= n; j++)
        {
            scanf("%d",&G[i][j]);
        }
    }  
}

void DFS(int s)
{
    int i;
    visited[s] = 1;
    printf("%d - ",s);

    for ( i = 1; i <= n; i++)
    {
        if ((G[s][i]==1) && (visited[i] == 0))
        {
            DFS(i);
        }
        
    }
    
}


int main()
{
    int start, i;
    scanf("%d",&n);

    getgraph();

    scanf("%d",&start);
    printf("\nTHE DFS GRAPH TRAVERSAL OF GRAPH IS :\n");
    DFS(start);

    for ( i = 1; i <= n; i++)
    {
        if(visited[i] == 0)
        DFS(i);
    }
    
}