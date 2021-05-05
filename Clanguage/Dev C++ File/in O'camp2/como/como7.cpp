#include <bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<string> a;
    priority_queue<string> b;
    int n;

    scanf("%d",&n);
    for(int i=1;i<n;i++){
        string x,y;
        cin>>x>>y;
        a.push(x);
        b.push(y);
    }

    while(true){
        if(a.top()==b.top()){
            a.pop();
            b.pop();
        }else{
            a.pop();
            if(a.top()!=b.top()){
                cout<<b.top();
            return 0;
        }
    }

}
}
