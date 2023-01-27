#include <stdio.h>
#define MAX 2000
#define BLACK 1
#define WHITE 0
#define INF 99999
#define NIL -1
void prim(void);
int n;
int T[MAX][MAX];
int pi[MAX];
int d[MAX];
int color[MAX];

int main()
{
    int cost = 0, tmp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            scanf("%d", &tmp);
            if (tmp == NIL)
            {
                tmp = INF;
            }
            T[i][j] = tmp;
        }
    }
    prim();
    for (int i = 0; i < n; i++)
    {
        cost += d[i];
    }
    printf("%d\n", cost);
    return 0;
}

void prim(void)
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
            if (color[i] != BLACK && T[u][i] < d[i])
            {
                pi[i] = u;
                d[i] = T[u][i];
            }
        }
    }
}