#include <stdio.h>
#define MAX 500000

int size;

int main(){

    int T[MAX];
    scanf("%d",&size);
    for(int i=1;i<size+1;i++){
        scanf("%d",&T[i]);
    }
    buildMaxHeap(T);
    for(int i=1;i<size+1;i++){
        printf(" %d",T[i]);
    }
    printf("\n");
    return 0;
}

void maxHeapify(int *A,int i){
    int l,r,largest,tmp;
    l = left(i);
    r = right(i);
    // 左の子、自分、右の子で値が最大のノードを選ぶ
    if (l <= size && A[l] > A[i]){
        largest = l;
    }
    else{
        largest = i;
    }
    if (r <=size && A[r] > A[largest]){
        largest = r;
    }

    if (largest != i){// i の子の方が値が大きい場合
        tmp=A[i];
        A[i]=A[largest];
        A[largest]=tmp;
        maxHeapify(A, largest); // 再帰的に呼び出し
    }
}

void buildMaxHeap(int *A){
    for (int i = size/2 ;i>=1;i--){
        maxHeapify(A, i);
    }
}

int left(int i){
    return i*2;
}

int right(int i){
    return i*2+1;
}