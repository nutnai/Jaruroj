#include <bits/stdc++.h>
using namespace std;

int main(){
    int dot,n,x,y,z;
    bool stop=false;

    cin>>dot>>n;
    vector<pair<int,int>> g[dot];
    int ans[dot];
    ans[0]=0;
    for(int i=1;i<dot;i++){
        ans[i]=INT_MAX;
    }

    for(int i=1;i<=n;i++){
        cin>>x>>y>>z;
        g[x].push_back(make_pair(y,z));
    }

    while(stop==false){
            stop=true;
        for(int i=0;i<dot;i++){
            for(int j=0;j<g[i].size();j++){
                int v,w;
                    v = g[i][j].first;
                    w = g[i][j].second;
                if(ans[v]>ans[i]+w){
                    ans[v]=ans[i]+w;
                    stop=false;
                }}}}
    for(int i=0;i<dot;i++)
        cout<<ans[i]<<endl;
}
