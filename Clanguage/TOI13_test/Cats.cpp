#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,ans=0;
    scanf("%lld",&n);
    for(long long i=0;i<n;i+=2){
        long long x,y;
        scanf("%lld%lld",&x,&y);
        if(x==y){
            continue;
        }else{  
        long long z=min(x,y);
        ans=max(z,ans);
        }
    }
    cout<<ans;
}