#include <bits/stdc++.h>
using namespace std;

int lis[200001];
int ans=0;

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        int a=1;
        while(num>lis[a] && lis[a]!=0){
            a++;
        }
        lis[a]=num;
        if(a>ans){
            ans++;
        }
    }
    cout<<ans;
}