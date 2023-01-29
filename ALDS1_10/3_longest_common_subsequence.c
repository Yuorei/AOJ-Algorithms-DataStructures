#include <stdio.h>
#include <string.h>
#define MAX 1001
int LCSLength(char *,char *);

int LCSLength(char *X,char *Y){
    int c[MAX][MAX];
    int m,n,max=0;
    m = strlen(X);
    n = strlen(Y);
    for (int i = 1 ;i<=m;i++){
        c[i][0] = 0;
    }
    for(int  j = 0 ;j<=n;j++){
        c[0][j]=0;
    }
    for (int i = 1 ;i<=m;i++){
        for(int  j = 1 ;j<=n;j++){
            if (X[i-1] == Y[j-1]){
                c[i][j] = c[i-1][ j-1] + 1;
            }
            else if (c[i-1][j] >= c[i][j-1]){
                c[i][j] = c[i-1][j];
            }
            else{
                c[i][j] = c[i][j-1];
            }
            max=max>c[i][j]?max:c[i][j];
        }
    }
    return max;
}
int main(){
    char S1[MAX],S2[MAX];
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s %s",S1,S2);
        m=LCSLength(S1,S2);
        printf("%d\n",m);
    }
    return 0;
}