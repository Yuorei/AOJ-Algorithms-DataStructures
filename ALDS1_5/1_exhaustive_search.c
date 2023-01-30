#include <iostream>
using namespace std;

bool solve(int ,int );


int A[2000],m[2000];
int n;
int main(){
    int q;
    bool res;
    cin>>n;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> m[i];
    }
    for(int j=0;j<q;j++){
        res=solve(0, m[j]);
        if(res){
            cout<<"yes"<<endl;
        }else{
            cout<<"no"<<endl;
        }
    }

    return 0;
}

bool solve(int i,int w){
    bool res;
    if (w == 0){
        return true;
    }
    if (i >= n){
        return false;
    }
    res = solve(i + 1, w) || solve(i + 1, w - A[i]);
    return res;
}