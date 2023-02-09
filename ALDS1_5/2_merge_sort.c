#include <stdio.h>
#define QUANTITY 500000
#define INFTY 1000000000
int count = 0;
void mergeSort(int *, int , int );
void merge(int*, int, int, int);

int main()
{
    int c = 0;
    int n, num, i;
    int A[QUANTITY];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    mergeSort(A, 0, n);
    for (i = 0; i < n; i++)
    {
        if (c == n - 1)
        {
            printf("%d", A[i]);
            break;
        }
        printf("%d ", A[i]);
        c++;
    }
    printf("\n");
    printf("%d\n", count);
    return 0;
}

void mergeSort(int A[], int left, int right)
{
    int mid;
    if (left + 1 < right)
    {
        mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

void merge(int A[], int left, int mid, int right)
{
    int n1, n2, j;
    int L[QUANTITY];
    int R[QUANTITY];
    int i;
    n1 = mid - left;
    n2 = right - mid;
    for (i = 0; i < n1; i++)
    {
        L[i] = A[left + i];
    }
    for (i = 0; i < n2; i++)
    {
        R[i] = A[mid + i];
    }
    L[n1] = INFTY;
    R[n2] = INFTY;
    i = 0;
    j = 0;
    for (int k = left; k < right; k++)
    {
        count++;
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
}