#include <stdio.h>
typedef struct  {
    char mark;
    int num;
} DATA;
// int partition(DATA *[],int , int );
// void quicksort(DATA *[], int ,int );

int partition(DATA *A,int p, int r){
    DATA tem;
    int x,i;
    x=A[r].num;
    i=p-1;
    for(int j =p;i<r;i++){
        if (A[j].num<=x){
            i+=1;
            tem=A[i];
            A[i]=A[j];
            A[j]=tem;
        }
    }
    tem=A[i+1];
    A[i+1]=A[r];
    A[r]=tem;
    return i+1;
}
void quickSort(DATA *A, int p,int r){
    int q;
    if (p < r){
        q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}


int main(){
    int n,q;
    DATA data[1000000];
    scanf("%d",&n);
    for(int i;i<n;i++){
        scanf("%c %d",&data[i].mark,&data[i].num);
    }
    quickSort(data, 0, n-1);
    printf("not\n");
    for(int i; i<n;i++){
        printf("%c %d",data[i].mark,data[i].num);
    }
}