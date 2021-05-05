#include <bits/stdc++.h>
using namespace std;

using pii=pair<int,int>;
using tiii=tuple<int,int,int>;

int por[100001];
int npor[100001];

int hapor(int x) {
    while(por[x]!=x)
        x=por[x];
    return x;
}

void luaumpor(int x,int y) {
    if(npor[x]<npor[y]) {
        por[x]=y;
    } else {
        por[y]=x;
        if(npor[x]==npor[y])
            npor[x]++;
    }
}

int main() {
    priority_queue<tiii,vector<tiii>,greater<tiii>> q;
    tuple<int,int,int> qq;
    int n;
    scanf("%d",&n);
    int power[n+1],ans=0;

    for(int i=1; i<=n; i++) {
        scanf("%d",&power[i]);
        por[i]=i;
        npor[i]=0;
    }
    int m;
    scanf("%d",&m);
    for(int i=1; i<=m; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        get<0>(qq)=power[x]+power[y];
        get<1>(qq)=x;
        get<2>(qq)=y;
        q.push(qq);
    }

    int line=0;
    while(line<n-1) {
        int numnug=get<0>(q.top());
        int from=get<1>(q.top());
        int to=get<2>(q.top());
        int porfrom=hapor(from);
        int porto=hapor(to);

        if(porfrom!=porto) {
            ans+=numnug;
            line++;
            luaumpor(porfrom,porto);
        }
        q.pop();
    }
    cout<<ans;
}
