#include <stdio.h>
int n;
int A[101][101] = {0};

int main()
{
    int u, k, tmp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &u, &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &tmp);
            A[u][tmp] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j == n)
            {
                printf("%d", A[i][j]);
                break;
            }
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    return 0;
}