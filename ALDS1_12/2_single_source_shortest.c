#include <stdio.h>
#define MAX 2000
#define BLACK 1
#define WHITE 0
#define INF 99999999
#define NIL -1
void dijkstra(void);
int n;
int T[MAX][MAX];
int pi[MAX];
int d[MAX];
int color[MAX];

int main()
{
    int u, k, v, c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            T[i][j] = INF;
        }
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &u, &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d %d", &v, &c);
            T[u][v] = c;
        }
    }
    dijkstra();
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", i, d[i]);
    }

    return 0;
}

void dijkstra()
{
    int mincost, u;
    for (int i = 0; i < n; i++)
    {
        d[i] = INF;
        pi[i] = NIL;
        color[i] = WHITE;
    }
    d[0] = 0;
    while (1)
    {
        mincost = INF;
        for (int i = 0; i < n; i++)
        {
            if (color[i] != BLACK && d[i] < mincost)
            {
                mincost = d[i];
                u = i;
            }
        }
        if (mincost == INF)
        {
            break;
        }
        color[u] = BLACK;
        for (int i = 0; i < n; i++)
        {
            if (color[i] != BLACK && d[u] + T[u][i] < d[i])
            {
                pi[i] = u;
                d[i] = d[u] + T[u][i];
            }
        }
    }
}