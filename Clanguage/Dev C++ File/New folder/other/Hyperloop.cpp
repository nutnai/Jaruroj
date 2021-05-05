#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,o;
    scanf("%d%d%d",&n,&m,&o);
    vector<pair<int,int>> graf[n+1];
    int por[n+1];

  	using pii = pair<int,int>;
    priority_queue<pii, vector<pii>, greater<pii>> q; // min heap creation

    int ans[n+1];
    int check[n+1];
    int st,en;
    scanf("%d%d",&st,&en);

    for(int i=0; i<n; i++) {
        check[i]=false;
        ans[i]=2e9;
        por[i] = -1;
    }
		q.push(make_pair(0,st));
    ans[st] = 0;

    for(int i=1; i<=m; i++) {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        graf[x].push_back(make_pair(y,z));
        graf[y].push_back(make_pair(x,z));
    }

    int Q;
    scanf("%d",&Q);


    while(!q.empty()) {
        int now=q.top().second;
        q.pop();
        if(check[now]) {
            continue;
        }
        check[now]=true;
        int rob=graf[now].size();
        for(int i=0; i<rob; i++) {
            int chee=graf[now][i].first;
            int numnug=graf[now][i].second;
            if(ans[chee]>ans[now]+numnug && numnug>o) {
                ans[chee]=ans[now]+numnug;
                por[chee]=now;
                q.push(make_pair(ans[chee],chee));
            }
        }
    }
    if(check[en]==false) {
        cout<<"-1";
        return 0;
    }

  	cout<<ans[en]<<"\n";

    if(Q==2) {
        vector<int> path; path.push_back(en);
        int now=en;
        while(por[now]!=-1) {
            path.push_back(por[now]);
            now=por[now];
        }
        cout<<path.size()<<"\n";
        while(!path.empty()) {
            cout<<path.back()<<" ";
            path.pop_back();
        }
    }
}

