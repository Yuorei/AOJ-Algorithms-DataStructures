#include <stdio.h>
#define MAX 44

int main(){
    int n;
    scanf("%d",&n);
    n=fibonacci(n);
    printf("%d\n",n);
    return 0;
}

int fibonacci(int n){
    int F[MAX];
    F[1]=F[0]=1;
    for(int i=2;i<=n;i++){
        F[i]=F[i-2]+F[i-1];
    }
    return F[n];
}