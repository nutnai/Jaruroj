#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> cost;

int bst(int x,int n){
    int l = 0;
    int r = n-1;
    int m;
    int ans=0;
    while(l<=r){
        m = (l+r)/2;
        if(cost[m].first <= x){
            ans = max(ans,cost[m].second);
            l = m + 1;
        }else{
            r = m - 1;
        }
    }
    return ans;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int pre = 0;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        cost.push_back({x+pre , i});
        pre = x+pre;
    }
    sort(cost.begin(),cost.end());
    int maxx=cost[0].second;
    for(int i=1;i<n;i++){
        if(maxx>=cost[i].second){
            cost[i].second = maxx;
        }else{
            maxx = cost[i].second;
        }
    }

    for(int i=0;i<m;i++){
        int x;
        scanf("%d",&x);
        cout<<bst(x,n)<<"\n";
    }
}