#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000
void CountingSort(int *, int *, int );

int main(){
    int *A, *B;
    int C[VMAX+1];
    int n;

    scanf("%d", &n);

    A = malloc(sizeof(int)*n+1);
    B = malloc(sizeof(int)*n+1);

    for(int i =1;i<=n;i++){
        scanf("%hd",&A[i]);
    }
    CountingSort(A, B, n);
    for(int i =1;i<=n;i++){
        if(i!=1) printf(" ");
        printf("%d",B[i]);
    }
    printf("\n");

    return 0;
}

void CountingSort(int *A, int *B, int n){
    int C[VMAX];
     for (int i = 0 ;i<=VMAX;i++){
         C[i] = 0;
     }

     /* C[i] に i の出現数を記録する */
     for (int j = 1;j<=n;j++){
         C[A[j]]++;
     }
     /* C[i] に i 以下の数の出現数を記録する*/
    for (int i = 1 ;i<=VMAX;i++){
        C[i] = C[i] + C[i-1];
    }
    for (int j = n;j>=1;j--){
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }
}
