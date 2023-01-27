#include <stdio.h>
#define QUANTITY 500000
#define INFTY 1000000000

typedef struct
{
    char mark;
    int num;
} DATA;

int partition(DATA A[], int p, int r)
{
    DATA tem;
    int x, i;
    x = A[r].num;
    i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (A[j].num <= x)
        {
            i += 1;
            tem = A[i];
            A[i] = A[j];
            A[j] = tem;
        }
    }
    tem = A[i + 1];
    A[i + 1] = A[r];
    A[r] = tem;
    return i + 1;
}
void quickSort(DATA A[], int p, int r)
{
    int q;
    if (p < r)
    {
        q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

int main()
{
    int n, q, m, stable = 1;
    char s[2];
    DATA data[1000000], data2[1000000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", s, &m);
        data2[i].num = data[i].num = m;
        data2[i].mark = data[i].mark = s[0];
    }
    quickSort(data, 0, n - 1);
    mergeSort(data2, 0, n);
    for (int i = 0; i < n; i++)
    {
        if (data[i].mark != data2[i].mark)
        {
            stable = 0;
        }
    }
    if (stable == 1)
    {
        printf("Stable\n");
    }
    else
    {
        printf("Not stable\n");
    }
    for (int i; i < n; i++)
    {
        printf("%c %d\n", data[i].mark, data[i].num);
    }
}

// todo Aをint→DATAにする
void merge(DATA A[], int left, int mid, int right)
{
    int n1, n2, j;
    DATA L[QUANTITY];
    DATA R[QUANTITY];
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
    L[n1].num = INFTY;
    R[n2].num = INFTY;
    i = 0;
    j = 0;
    for (int k = left; k < right; k++)
    {
        if (L[i].num <= R[j].num)
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

void mergeSort(DATA A[], int left, int right)
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