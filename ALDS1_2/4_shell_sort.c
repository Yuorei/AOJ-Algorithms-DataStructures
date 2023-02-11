#include <stdio.h>

#define MAX 1000000

int n;
int G[20], A[MAX];
int count;

void insertionSort(int m)
{
    int j, key;
    for (int k = m - 1; k >= 0; k--)
    {
        for (int i = G[k]; i < n; i++)
        {
            key = A[i];
            j = i - G[k];
            while (j >= 0 && A[j] > key)
            {
                A[j + G[k]] = A[j];
                j = j - G[k];
                count++;
            }
            A[j + G[k]] = key;
        }
    }
}

int shellSort()
{

    int m = 0, x = 1;
    for (int i = 0; x <= n; i++)
    {
        G[i] = x;
        x = x * 3 + 1;
        m++;
    }
    insertionSort(m);
    return m;
}

void show(int m)
{
    printf("%d\n", m); // Gの長さ
    for (int i = m - 1; i >= 0; i--)
    {
        printf("%d\n", G[i]);
    }
    printf("%d\n", count);
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", A[i]);
    }
}

int main()
{
    int m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    m = shellSort();
    show(m);
    return 0;
}