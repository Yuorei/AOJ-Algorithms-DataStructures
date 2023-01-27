#include <stdio.h>
#define MAX 2000
#define BLACK 1
#define WHITE 0
#define INF 9999999999
#define NIL -1
int n;
int T[MAX][MAX];
int main()
{
    scanf("%d" & n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &T[i][j]);
        }
    }

    return 0;
}

prim(G, w, r)
{
for each u in G
    {
        d[u] = INF;
        pi[u] = NIL;
        color[u] = WHITE;
    }
d[r] = 0;
while (1)
{
    mincost = INF;
    for (each i in G)
    {
        if (color[i] != BLACK and d[i] < mincost)
        {
            mincost = d[i] u = i;
        }
    }
    if (mincost == INF)
    {
        break;
    }
    color[u] = BLACK;
    for (each v in Adj[u])
    {
        if (color[v] != BLACK and w(u, v) < d[v])
        {
            pi[v] = u;
            d[v] = w(u, v);
        }
    }
}
}