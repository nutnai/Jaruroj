#include <bits/stdc++.h>
using namespace std;

typedef vector<pair<int,int>> vpii;

int main(){
    int t,q;
    scanf("%d %d",&t,&q);
    vpii data[t+3];
    vector<int> lengthbase[1003];
    for(int i=0;i<t;i++){
        int Long;
        scanf("%d",&Long);
        lengthbase[Long].push_back(i);
        for(int j=0;j<Long-1;j++){
            int x,y;
            scanf("%d %d",&x,&y);
            int l = min(x,y);
            int r = max(x,y);
            data[i].push_back({l,r});
        }
        sort(data[i].begin(),data[i].end());
    }

    vpii check[q+3];
    for(int i=0;i<q;i++){
        int ans=0;
        int Long;
        scanf("%d",&Long);
        for(int j=0;j<Long-1;j++){
            int x,y;
            scanf("%d %d",&x,&y);
            int l = min(x,y);
            int r = max(x,y);
            check[i].push_back({l,r});
        }
        if(lengthbase[Long].empty()){
            cout<<"0\n";
            continue;
        }
        sort(check[i].begin(),check[i].end());

        for(auto x:lengthbase[Long]){
            bool tf = true;
            for(int c=0;c<Long-1;c++){
                if(data[x][c].first != check[i][c].first){
                    tf = false;
                    break;
                }
                if(data[x][c].second != check[i][c].second){
                    tf = false;
                    break;
                }
            }
            if(tf){
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
}