#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;

int main(){
    int t;
    scanf("%d",&t);
    set<pair<int,int>> pai[t];

    for(int tcase=0;tcase<t;tcase++){
        int l,r,need;
        priority_queue<tiii,vector<tiii>,greater<tiii>> pq;
        scanf("%d %d %d",&l,&r,&need);
        if(l+r<need || (l==r && r!=need)){
            cout<<"-1\n";
            continue;
        }

        //จำนวนครั้ง น้ำในซ้าย น้ำในขวา
        pq.push({0,0,0});
        int ans = -1;
        while(!pq.empty()){
            int n = get<0>(pq.top());
            int lh = get<1>(pq.top());
            int rh = get<2>(pq.top());
            pq.pop();
            
            if(pai[tcase].find({lh,rh}) != pai[tcase].end()){
                continue;
            }else pai[tcase].insert({lh,rh});

            if(lh == need || rh == need){
                ans = n;
                break;
            }
            //เติมซ้าย
            if(lh != l){
                pq.push({n+1,l,rh});
            }
            //เติมขวา
            if(rh != r){
                pq.push({n+1,lh,r});
            }
            //เทซ้าย
            if(lh != 0 ){
                pq.push({n+1,0,rh});
            }
            //เทขวา
            if(rh != 0){
                pq.push({n+1,lh,0});
            }
            //เทจาก ซ้าย ไป ขวา
            if(lh != 0 && rh != r){
                int ll = (r-rh>=lh)?0:lh-(r-rh);
                int rr = (rh+lh>=r)?r:lh+rh;
                pq.push({n+1, ll , rr});
            }
            //เทจาก ขวา ไป ซ้าย
            if(rh != 0 && lh != l){
                int ll = (lh+rh>=l)?l:lh+rh;
                int rr = (l-lh>=rh)?0:rh-(l-lh);
                pq.push({n+1, ll , rr});
            }
        }
        cout<<ans<<"\n";
        while(!pq.empty()){
            pq.pop();
        }
    }
}