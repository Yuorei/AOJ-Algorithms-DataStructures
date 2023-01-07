#include <stdio.h>
#define NIL -1
#define MAX 100000

typedef struct{
    int pearent;
    int left_child;
    int right_sibling;
    int depth;
}NODE;

NODE Q[MAX];
int n;
int main(){
    int m,num,id,l,k;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        Q[i].pearent=NIL;
        Q[i].left_child=NIL;
        Q[i].right_sibling=NIL;
        Q[i].depth=0;
    }
    for(int i=0 ; i<n;i++){
        scanf("%d%d",&id,&m);
        for(int j=0;j<m;j++){
            scanf("%d",&num);
            if(j==0){
                Q[id].left_child=num;
            }
            else{
                Q[l].right_sibling=num;
            }
            l=num;
            Q[num].pearent=id;
        }
    }

    for(int i=0;i<n;i++){
        m=i;
        while(Q[m].pearent!=NIL){
            m=Q[m].pearent;
            Q[i].depth++;
        }
        if(Q[i].pearent==NIL){
            printf("node %d: parent = %d, depth = %d, root, [",i,Q[i].pearent,Q[i].depth);
            l=Q[i].left_child;
            k=0;
            while (l!=NIL)
            {
                if(k==0){
                    printf("%d",l);
                    k++;
                }
                else{
                    printf(", %d",l);
                }
                l=Q[l].right_sibling;
            }
            printf("]\n");
        }
        else if(Q[i].left_child==NIL){
            printf("node %d: parent = %d, depth = %d, leaf, []\n",i,Q[i].pearent,Q[i].depth);
        }
        else {
            printf("node %d: parent = %d, depth = %d, internal node, [",i,Q[i].pearent,Q[i].depth);
            l=Q[i].left_child;
            k=0;
            while (l!=NIL)
            {
                if(k==0){
                    printf("%d",l);
                    k++;
                }
                else{
                    printf(", %d",l);
                }
                l=Q[l].right_sibling;
            }
            printf("]\n");
        }
    }
    return 0;
}