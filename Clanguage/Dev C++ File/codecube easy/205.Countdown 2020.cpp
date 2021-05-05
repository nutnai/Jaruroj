#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int ka[n+1];
    float ans[n+1];
    for(int i=1;i<=n;i++){
        scanf("%d",&ka[i]);
        ans[i]=0;
    }
    int chee=1;
    while(chee+m-1<=n){
        for(int i=chee;i<=chee+m-1;i++){
            ans[chee]+=ka[i];
        }
        chee++;
    }
    chee--;
    cout<<chee<<"\n";
    for(int i=1;i<=chee;i++){
        ans[i]/=m;
        printf("%.6f ",ans[i]);
    }
    return 0;
}
