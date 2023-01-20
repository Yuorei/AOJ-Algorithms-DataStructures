#include <stdio.h>
#define NIL -1
#define MAX 100000

int sibling(int );
int degree(int );
int hight(int);

typedef struct{
    int pearent;
    int left;
    int right;
    int depth;
    int hight;
}NODE;

NODE Q[MAX];
int n;

int main(){
    int m,id,left,right,sib,deg;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        Q[i].pearent=NIL;
        Q[i].left=NIL;
        Q[i].right=NIL;
        Q[i].depth=0;
        Q[i].hight=0;
    }

    for(int i=0 ; i<n;i++){
        scanf("%d%d%d",&id,&left,&right);
        Q[id].left=left;
        Q[id].right=right;
        if(left!=NIL){
            Q[left].pearent=id;
        }
        if(right!=NIL){
            Q[right].pearent=id;
        }
    }

    for(int i=0;i<n;i++){
        m=i;
        while(Q[m].pearent!=NIL){
            m=Q[m].pearent;
            Q[i].depth++;
        }

        sib=sibling(i);
        deg=degree(i);
        Q[i].hight=hight(i);
        if(Q[i].pearent==NIL){
            printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, root\n",i,Q[i].pearent,sib,deg,Q[i].depth,Q[i].hight);
        }
        else if(Q[i].left==NIL && Q[i].right==NIL){
            printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, leaf\n",i,Q[i].pearent,sib,deg,Q[i].depth,Q[i].hight);
        }
        else {
            printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, internal node\n",i,Q[i].pearent,sib,deg,Q[i].depth,Q[i].hight);
        }
    }
    return 0;
}

int sibling(int x){
    if(Q[x].pearent==NIL){
        return NIL;
    }
    if(Q[Q[x].pearent].left!=x && Q[Q[x].pearent].left!=NIL){
        return Q[Q[x].pearent].left;
    }
    if(Q[Q[x].pearent].right!=NIL && Q[Q[x].pearent].right!=x){
        return Q[Q[x].pearent].right;
    }
    return NIL;
}

int degree(int x){
    int c=0;
    if(Q[x].left!=NIL) c++;
    if(Q[x].right!=NIL) c++;
    return c;
}

int hight(int x){
    int h1=0,h2=0;
    if(Q[x].right!=NIL){
        h1=hight(Q[x].right)+1;
    }
    if(Q[x].left!=NIL){
        h2=hight(Q[x].left)+1;
    }
    if(h1>h2){
        return h1;
    }
    else{
        return h2;
    }
}