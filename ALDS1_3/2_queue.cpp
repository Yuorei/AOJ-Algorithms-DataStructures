#include <iostream>
using namespace std;

#define LEN 100005

typedef struct pp{
  char name[100];
  int t;
}P;

void enqueue(P);
P dequeue(void);
int isEmpty(void);




P Q[LEN+1];
int head=0, tail=0, n;


int main(){
    int q,need_time;
    P u;
    cin >> n >> need_time;
    q=0;
    for(int i=1;i<=n;i++){
        cin>> Q[i].name >> Q[i].t;
        enqueue(Q[i]);
    }
    while(1){
        u=dequeue();
        if(u.t==-1)break;
        if(u.t-need_time>0){
            q+=need_time;
            u.t-=need_time;
            enqueue(u);
        }
        else{
            q+=u.t;
            cout<< u.name<<" "<< q<<endl;
        }
    }
    return 0;
}

void enqueue(P x){
    Q[tail] = x;
    if(tail+1==LEN)tail=0;
    else tail++;
}

P dequeue(){
    P x;
    int cheack;
    cheack=isEmpty();
    if(cheack==0){
        x.t=-1;
        return x;
    }
    x = Q[head];
    if(head+1==LEN){
        head=0;
    }
    else {
        head++;
    }
    return x;
}

int isEmpty(){
    if (head == tail){
        return 0;
    }
    else{
        return 1;
    }
}