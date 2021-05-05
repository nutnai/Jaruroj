#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef tuple<int,int,vector<pii>> wtf;

vector<pii> data;
int n;

wtf pu(int x,int y,vector<pii> z){
    wtf temp;
    get<0>(temp) = x;
    get<1>(temp) = y;
    get<2>(temp) = z;
    return temp;
}

int main() {
    scanf("%d",&n);

    for(int i=0; i<n; i++) {
        int x,y;
        scanf("%d %d",&x,&y);
        data.push_back({x,y});
    }
    priority_queue<wtf,vector<wtf>,greater<wtf>> pq;

    for(int i=0;i<n;i++){
        vector<pii> temp = data;
        temp.erase(temp.begin()+i);
        pq.push(pu(0,data[i].second,temp));
    }

    while(!pq.empty()){
        int ka = get<0>(pq.top());
        int speed = get<1>(pq.top());
        vector<pii> next = get<2>(pq.top());
        pq.pop();
        if(next.empty()){
            cout<<ka;
            return 0;
        }
        for(int i=0;i<next.size();i++){
            int innext = next[i].first;
            int outnext = next[i].second;
            if(innext >= speed){
                vector<pii> temp = next;
                temp.erase(temp.begin()+i);
                pq.push(pu(ka,outnext,temp));
            }else{
                int pluss = speed - innext;
                vector<pii> temp = next;
                temp.erase(temp.begin()+i);
                pq.push(pu(ka+pluss,outnext,temp));
            }
        }

    }

}
