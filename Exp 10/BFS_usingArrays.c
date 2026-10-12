#include <stdio.h>

#define MAX 100

int main()
{
    int n, start;
    int adj[MAX][MAX];
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = -1;

    /* Read number of vertices */
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    /* Read adjacency matrix */
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    /* Read starting vertex */
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    /* Mark starting vertex as visited */
    visited[start] = 1;

    /* Insert starting vertex into queue */
    rear++;
    queue[rear] = start;

    printf("BFS Traversal: ");

    /* Repeat until queue becomes empty */
    while (front <= rear)
    {
        /* Delete front vertex */
        int u = queue[front];
        front++;

        /* Visit the vertex */
        printf("%d ", u);

        /* Check all adjacent vertices */
        for (int v = 0; v < n; v++)
        {
            if (adj[u][v] == 1 && visited[v] == 0)
            {
                /* Mark vertex as visited */
                visited[v] = 1;

                /* Insert vertex into queue */
                rear++;
                queue[rear] = v;
            }
        }
    }

    printf("\n");
    return 0;
}