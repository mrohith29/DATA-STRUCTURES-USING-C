#include <stdio.h>

#define max 10
int visited[max] = {0};
int G[max][max];
int q[max];
int n, r = -1, f = -1;

int dequeue()
{
    int ver;
    if (f == -1)
    {
        printf("\n Q Underflow\n");
        return -1;
    }
    ver = q[f];
    if (r == f)
        r = f = -1;
    else
        f++;
    return ver;
}

void enqueue(int v)
{
    if (r == max - 1)
    {
        printf("Q Overflow\n");
        return;
    }
    q[++r] = v;
    if (r == 0)
        f = 0;
}

void BFS(int v)
{
    int i, res;
    visited[v] = 1;
    enqueue(v);
    while (f != -1)
    {
        res = dequeue();
        printf("%d - ", res);
        for (i = 1; i <= n; i++)
        {
            if (G[res][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

void getadjmatrix()
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &G[i][j]);
        }
    }
}

int main()
{
    int start, i;
    scanf("%d", &n);
    getadjmatrix();
    scanf("%d", &start);
    printf("The BFS Trraversal of Graph is : ");  
    BFS(start);
    for (i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            BFS(i);
        }
    }
}