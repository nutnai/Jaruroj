#include <bits/stdc++.h>
using namespace std;

int st,fn,node,bpm,ans=2e9;
int graf[10000][10000];
bool check[10000];

void kit(int now,int kaow,int numnug) {
    if(now==fn)
        if(kaow%bpm==0) {
            ans=min(ans,numnug);
            memset(check,false,node+1);
        } else{
            memset(check,false,node+1);

        }

    for(int i=1; i<=node; i++) {

        int c=graf[now][i];
        if(c!=0&&!check[i]) {
            check[i]=true;
            kit(i,kaow+1,numnug+c);
        }
    }
}

int main() {
    int link;
    scanf("%d%d%d",&node,&link,&bpm);
    scanf("%d%d",&st,&fn);

    for(int i=1; i<=link; i++) {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        graf[x][y]=z;
    }
    int kaow=1,numnug=0;
    kit(st,kaow,numnug);
    cout<<ans;
}
