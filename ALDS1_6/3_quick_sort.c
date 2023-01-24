#include <stdio.h>
#define QUANTITY 500000
#define INFTY 1000000000

typedef struct  {
    char mark;
    int num;
} DATA;

int partition(DATA A[],int p, int r){
    DATA tem;
    int x,i;
    x=A[r].num;
    i=p-1;
    for(int j =p;j<r;j++){
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
void quickSort(DATA A[], int p,int r){
    int q;
    if (p < r){
        q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}


int main(){
    int n,q;
    char s[2];
    DATA data[1000000];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s %d",s,&data[i].num);
        data[i].mark=s[0];
    }
    quickSort(data, 0, n-1);
    printf("Not stable\n");
    for(int i; i<n;i++){
        printf("%c %d\n",data[i].mark,data[i].num);
    }
}

