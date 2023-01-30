#include <stdio.h>

#define LEN1 10001
#define LEN2 501

int n,q,c,r;
int s[LEN1],t[LEN2];

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&s[i]);
    }
    scanf("%d",&q);
    for(int j=0;j<q;j++){
        scanf("%d",&t[j]);
    }
    for(int i=0;i<q;i++){
        r=linearSearch(t[i]);
        if(r>0){
            c++;
        }
    }
    
    printf("%d\n",c);
}

int linearSearch(int key)  {
    int i=0;
    s[n] = key;
    while(s[i]!=key)
    {
        i++;
    }
    if (i==n){
        return -1;
    }
    return 1;
}