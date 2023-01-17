#include <stdio.h>
#define MAX 250

int main(){
    int size;
    int T[MAX];
    scanf("%d",&size);
    for(int i=1;i<size+1;i++){
        scanf("%d",&T[i]);
    }
    for(int i=1;i<size+1;i++){
        printf("node %d: key = %d, ",i,T[i]);
        if(i/2>=1){
            printf("parent key = %d, ",T[i/2]);
        }
        if(i*2<=size){
            printf("left key = %d, ",T[i*2]);
        }
        if(i*2<size){
            printf("right key = %d, ",T[i*2+1]);
        }
        printf("\n");
    }
    return 0;
}