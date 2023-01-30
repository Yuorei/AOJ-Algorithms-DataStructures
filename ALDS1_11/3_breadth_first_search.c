#include <stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX 100
#define INF 1000000000

int dequeue();
void enqueue(int);
void bfs(void);

int T[MAX][MAX] = {0};
int color[MAX] = {0};
int d[MAX];
int Q[MAX], n, head = 0, tail = 0;

int main()
{
    int u, k, tmp, v;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &u, &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &v);
            T[u - 1][v - 1] = GRAY;
        }
    }

    bfs();
    for (int i = 0; i < n; i++)
    {
        if (color[i] == BLACK)
        {
            printf("%d %d\n", i + 1, d[i]);
        }
        else
        {
            printf("%d -1\n", i + 1);
        }
    }
    return 0;
}

void bfs()
{
    int u;
    for (int j = 0; j < n; j++)
    {
        if (T[0][j] == GRAY)
        {
            color[j] = WHITE;
        }
    }
    for (u = 0; u < n; u++)
    {
        color[u] = WHITE;
        d[u] = INF;
    }
    color[0] = GRAY;
    d[0] = 0;
    enqueue(0);
    while (head != tail)
    {
        u = dequeue();
        for (int v = 0; v < n; v++)
        {
            if (T[u][v]==GRAY&&color[v] == WHITE)
            {
                color[v] = GRAY;
                d[v] = d[u] + 1;
                enqueue(v);
            }
        }
        color[u] = BLACK;
    }
}

int dequeue()
{
    int x;
    x = Q[head];
    if (head + 1 == MAX)
        head = 0;
    else
        head++;
    return x;
}

void enqueue(int x)
{
    Q[tail] = x;
    if (tail + 1 == MAX)
        tail = 0;
    else
        tail++;
}