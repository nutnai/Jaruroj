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
        por[x]=hapor(y);
    } else {
        por[y]=hapor(x);
        if(npor[x]==npor[y])
            npor[x]++;
    }
}

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    priority_queue<tiii,vector<tiii>,greater<tiii>> q;
    priority_queue<pii,vector<pii>,greater<pii>> ans;
    tuple<int,int,int> qq;

    for(int i=1; i<=m; i++) {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        get<0>(qq)=z;
        get<1>(qq)=x;
        get<2>(qq)=y;
        q.push(qq);
    }
    for(int i=1; i<=n; i++) {
        por[i]=i;
        npor[i]=0;
    }

    int line=0;
    while(line<n-1) {
        int numnug=get<0>(q.top());
        int from=get<1>(q.top());
        int to=get<2>(q.top());

        int x=hapor(from);
        int y=hapor(to);
        if(x!=y) {
            luaumpor(x,y);
            line++;
            ans.push({from,to});
        }
        q.pop();
    }

    while(!ans.empty()){
        cout<<get<0>(ans.top())<<" "<<get<1>(ans.top())<<"\n";
        ans.pop();
    }
}
