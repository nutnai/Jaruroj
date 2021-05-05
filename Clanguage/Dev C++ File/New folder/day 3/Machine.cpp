#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    char c;
    priority_queue<int,vector<int>> data;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf(" %c",&c);
        if(c=='P'){
            int x;
            scanf("%d",&x);
            data.push(x);
        }else
        if(!data.empty()){
            cout<<data.top()<<"\n";
            data.pop();
        }else cout<<"-1"<<"\n";
    }
}
