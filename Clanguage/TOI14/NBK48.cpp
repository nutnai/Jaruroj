#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    vector<pair<int,int>> cost;
    int pre=0;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        int temp=x+pre;
        cost.push_back({temp,i});
        pre=temp;

    }
    sort(cost.begin(),cost.end());
    for(int i=0;i<m;i++){
        int x;
        scanf("%d",&x);
        int ans=0;
        for(auto c:cost){
            if(x<c.first){
                break;
            }else if(ans<c.second){
                ans=c.second;
            }
        }
        cout<<ans<<"\n";
    }
}