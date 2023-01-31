#include <stdio.h>
#define N 8 //8x8
#define NOT_FREE -1
#define FREE 2
#define TRUE 1
#define FALSE 0
void putQueen(int );
void printBoard(void);

int col[8]={0};
int row[8]={0};
int dpos[100]={0};
int dneg[100]={0};
int field[8][8];

int main(){
    for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
            field[i][j]=FALSE;
        }
	}
    int n,r,c;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&r,&c);
        field[r][c]=TRUE;
    }
    putQueen(0);
    return 0;
}

void putQueen(int i){ // i行目
    if (i == N){
        printBoard();
        return;
    }
    for (int j = 0 ; j<N;j++){ // j列
        if (col[j] == NOT_FREE ||dpos[i+j] == NOT_FREE || dneg[i-j+N-1] == NOT_FREE){
            continue;
        }
        
        // put a queen at (i, j)
        row[i] = j;
        col[j] = dpos[i+j] = dneg[i-j+N-1] = NOT_FREE;
        // try the next row
        putQueen(i+1);
        // remove the queen at (i, j) for backtracking
        row[i]=col[j] = dpos[i+j] = dneg[i-j+N-1] = FREE;
        
        
    }
}

void printBoard(){
    for(int r=0;r<N;r++){
		for(int c=0;c<N;c++){
            if(field[r][c] &&row[r]!=c){
                return;
            }
        }
	}
    for(int r=0;r<N;r++){
		for(int c=0;c<N;c++){
            printf("%c",(row[r]==c)?'Q':'.'); // rowに結果が入っている？
        }
        printf("\n");
	}
}