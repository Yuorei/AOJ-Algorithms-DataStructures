#include <stdio.h>
#define NIL -1
#define MAX 100005

typedef struct{
    int id;
    int node;
    int pearent;
    int depth;
    int child_som;
    int child_node_list[MAX];
}INFOMATION;
int main(){
    INFOMATION Q[MAX];
    
    int n,m,tmp,id;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        Q[i].pearent=-1;
        Q[i].depth=0;
        Q[i].child_node_list[0]=NIL;
    }
    for(int i=0 ; i<n;i++){
        scanf("%d%d",&id,&m);
        Q[id].id=id;
        Q[id].child_som=m;
        for(int j=0;j<m;j++){
            scanf("%d",&tmp);
            Q[id].child_node_list[j]=tmp;
            Q[Q[id].child_node_list[j]].pearent=Q[id].id;
        }
    }
    
    for(int i=0;i<n;i++){
        m=i;
        while(Q[m].pearent!=-1){
            m=Q[m].pearent;
            Q[i].depth++;
        }
        if(Q[i].pearent==-1){
            printf("node %d: parent = %d, depth = %d, root, [",Q[i].id,Q[i].pearent,Q[i].depth);
            if(Q[i].child_node_list[0]!=NIL){
                printf("%d",Q[i].child_node_list[0]);
            }
            for(int j=1;j<Q[i].child_som;j++){
                printf(", %d",Q[i].child_node_list[j]);
            }
            printf("]\n");
        }
        else if(Q[i].child_node_list[0]==NIL){
            printf("node %d: parent = %d, depth = %d, leaf, []\n",Q[i].id,Q[i].pearent,Q[i].depth);
        }
        else {
            printf("node %d: parent = %d, depth = %d, internal node, [",Q[i].id,Q[i].pearent,Q[i].depth);
            printf("%d",Q[i].child_node_list[0]);
            for(int j=1;j<Q[i].child_som;j++){
                printf(", %d",Q[i].child_node_list[j]);
            }
            printf("]\n");
        }
    }
    return 0;
}