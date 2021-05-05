#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,minn=2e9+1,maxx=-2e9-1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        minn=min(minn,x);
        maxx=max(maxx,x);
    }
    cout<<minn<<"\n"<<maxx;
    return 0;
}