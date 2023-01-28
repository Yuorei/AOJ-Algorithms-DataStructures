#include <stdio.h>
#define INF 99999999999
#define MAX 2000000
int A[MAX];
int heap_size;

int heapExtractMax(){
    int max;
    if (heap_size < 1){
        printf("エラー\n");
        return -1 ;
    }
    max=A[1];
    A[1]=A[heap_size];
    heap_size--;
    maxHeapify( 1);
    return max;
}
void maxHeapInsert(int key){
    heap_size++;
    A[heap_size] = -INF;
    heapIncreaseKey(heap_size, key);
}
void heapIncreaseKey(int i,int key){
    int tmp;
    if (key < A[i]){
        printf("エラー\n");
        return;
    }
    A[i] = key;
    while (i > 1 && A[i/2] < A[i]){
        tmp=A[i];
        A[i]=A[i/2];
        A[i/2]=tmp;
        i=i/2;
    }
}

void maxHeapify(int i){
    int l,r,largest,tmp;
    l = left(i);
    r = right(i);
    // 左の子、自分、右の子で値が最大のノードを選ぶ
    if (l <= heap_size && A[l] > A[i]){
        largest = l;
    }
    else{
        largest = i;
    }
    if (r <=heap_size && A[r] > A[largest]){
        largest = r;
    }

    if (largest != i){// i の子の方が値が大きい場合
        tmp=A[i];
        A[i]=A[largest];
        A[largest]=tmp;
        maxHeapify(largest); // 再帰的に呼び出し
    }
}
int left(int i){
    return i*2;
}

int right(int i){
    return i*2+1;
}

int main(){
    int k,tmp;
    char S[10];
    while(1){
        scanf("%s",S);
        if(S[2]=='d'){
            break;
        }else if(S[0]=='i'){
            scanf("%d",&k);
            maxHeapInsert(k);
        }else{
            tmp=heapExtractMax();
            printf("%d\n",tmp);
        }
    }
    return 0;
}
