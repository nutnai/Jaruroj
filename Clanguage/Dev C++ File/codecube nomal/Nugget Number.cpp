#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,ans=6;
    int data[3]={6,9,20};
    scanf("%d",&n);
    if(n<6){
        cout<<"no";
        return 0;
    }
    while(ans<=n){
        cout<<ans;
    }
}
