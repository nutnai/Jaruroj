#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,last=0;
    scanf("%d%d",&n,&m);
    string s;
    int ka[n+1];
    ka[0]=0;
    for(int i=1;i<=n;i++){
        cin>>s;
        int x=(s=="UR"?1:0);
        ka[i]=ka[i-1]+x;
    }
    for(int i=1;i<=n-m+1;i++){
            int ans=ka[i+m-1]-ka[i-1];
        last=max(last,ans);
    }
    cout<<last;
}
