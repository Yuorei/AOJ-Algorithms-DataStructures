#include <stdio.h>
#define MAX 100
#define INF 10000000

int n;
int p[MAX];
int m[MAX][MAX];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&p[i],&p[i+1]);
    }
    matrrixChainOrder();
    printf("%d\n",m[1][n]);
    return 0;

}

void matrrixChainOrder(){
    int j,q;
    for(int i=1;i<=n;i++){
        m[i][i]=0;
    }
    for(int l=2;l<=n;l++){
        for(int i=1;i<=n-l+1;i++){
            j =i+l-1;
            m[i][j]=INF;
            for(int k = i;k<=j-1;k++){
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                m[i][j]=((m[i][j] <= q)?  m[i][j] : q);
            }
        }
    }
}