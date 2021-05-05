#include <bits/stdc++.h>
using namespace std;

int main() {
    int gun,path,tc,m;
    scanf("%d%d%d%d",&gun,&path,&tc,&m);
    int tumnank[gun];
    bool check[tc][gun];
    int tumnankpart;
    for(int i=0; i<gun; i++) {
        scanf("%d",&tumnank[i]);
        for(int u=0;u<tc;u++){
            check[u][i]=false;
        }
    }
    for(int i=0; i<tc; i++) {
        int ans=0;
        for(int j=0; j<path; j++) {
            int tumnankpath;
            scanf("%d",&tumnankpath);
            int st=tumnankpath-m;
            int fn=tumnankpath+m;
            for(int k=0; k<gun; k++) {
                if(tumnank[k]<st)
                    continue;
                if(tumnank[k]>fn)
                    break;
                    if(!check[i][k]){
                    ans++;
                    check[i][k]=true;
                    }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
