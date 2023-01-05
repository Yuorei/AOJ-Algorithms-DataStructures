#include <stdio.h>
#include <string.h>
#define M 1000187
#define L 14

char H[M][L]; /* Hash Table */

int getChar(char ch){
    if ( ch == 'A') return 1;
    else if ( ch == 'C') return 2;
    else if ( ch == 'G') return 3;
    else if ( ch == 'T') return 4;
    return 0;
}


long long getKey(char str[]){
    long long sum = 0, p = 1, i;
    for ( i = 0; i < strlen(str); i++ ){
        sum += p*(getChar(str[i]));
        p *= 5;
    }
    return sum;
}

int h1(int key){
    return key%M ;
}
int h2(int key){
    return 1+(key%(M-1));
}
int h(int key,int i){ 
    return (h1(key)+ i * h2(key))% M ;
}

int find(char str[]){
    int i=0,j,key;
    key=getKey(str);
    while(1){
        j=h(key,i);
        if(strcmp(H[j],str)==0){
            return 1;
        }
        else if(H[j][0]=='\0' || i>=M){
            return -1;
        }
        else{
            i++;
        }
    }
    return 0;

}

int insert(char str[]){
    int i=0,j,key;
    key=getKey(str);
    while(1){
        j=h(key,i);
        if(H[j][0]=='\0'){
            strcpy(H[j],str);
            return 1;
        }
        else{
            i++;
        }
    }
}

int main(){
    int i, n, h;
    char str[L], com[9];
    for ( i = 0; i < M; i++ ) H[i][0] = '\0';
    scanf("%d", &n);
    for ( i = 0; i < n; i++ ){
        scanf("%s %s", com, str);
        if ( com[0] == 'i' ){
            insert(str);
        }
        else{
            if (find(str)==1){
                printf("yes\n");
            }
            else{
                printf("no\n");
            }
        }
    }
    return 0;
}

