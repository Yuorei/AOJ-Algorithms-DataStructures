#include <stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX 101

int next(int);
void push(int);
void pop(void);
void visit(int);
void dfs(void);

int n, time = 0;
int T[MAX][MAX] = {0};
int color[MAX] = {0};
int d[MAX];
int stack[MAX];
int finsh[MAX];
int nt[MAX] = {0};
int top = 0;

int main()
{
    int u, k, tmp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            T[i][j] = WHITE;
        }
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &u, &k);
        u--;
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &tmp);
            tmp--;
            T[u][tmp] = 1;
        }
    }
    dfs();
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d\n",i+1,d[i],finsh[i]);
    }
    return 0;
}

void dfs()
{
    for (int u = 0; u < n; u++)
    {
        if (color[u] == WHITE)
        {
            visit(u);
        }
    }
}

void visit(int r)
{
    int u, v;
    push(r);
    color[r] = GRAY;
    d[r] = ++time;
    while (top != WHITE)
    {
        u = stack[top];
        v = next(u);
        if (v != -1)
        {
            if (color[v] == WHITE)
            {
                push(v);
                color[v] = GRAY;
                d[v] = ++time;
            }
        }
        else
        {
            pop();
            color[u] = BLACK;
            finsh[u] = ++time;
        }
    }
}

void push(int x)
{
    top++;
    stack[top] = x;
}

void pop()
{
    int x;
    top--;
}

int next(int u)
{
    for (int i = nt[u]; i < n; i++)
    {
        nt[u] = i + 1;
        if (T[u][i] == 1)
        {
            return i;
        }
    }
    return -1;
}