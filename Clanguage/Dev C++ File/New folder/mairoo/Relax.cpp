#include <bits/stdc++.h>
using namespace std;

map<int,int> m[6];

int main() {
    int n;
    scanf("%d",&n);

    for(int i=1; i<=n; i++) {
        int x;
        scanf("%d",&x);
        if(x<-1e6)
            m[0][x]=i;
        else if(x<-1e3)
            m[1][x]=i;
        else if(x<0)
            m[2][x]=i;
        else if(x<1e3)
            m[3][x]=i;
        else if(x<1e6)
            m[4][x]=i;
        else
            m[5][x]=i;
    }

    int mk;
    scanf("%d",&mk);
    for(int i=0; i<mk; i++) {
        int x,ans;
        scanf("%d",&x);
        if(x<-1e6)
            ans=m[0][x];
        else if(x<-1e3)
            ans=m[1][x];
        else if(x<0)
            ans=m[2][x];
        else if(x<1e3)
            ans=m[3][x];
        else if(x<1e6)
            ans=m[4][x];
        else
            ans=m[5][x];

        if(ans!=0)
            cout<<ans<<"\n";
        else
            cout<<"Not found\n";
    }
}
