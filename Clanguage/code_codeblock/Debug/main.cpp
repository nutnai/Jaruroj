#include <bits/stdc++.h>
using namespace std;

#define kanat 200002
typedef pair<int,int> pii;
vector<pii> data[kanat];
int n,m;


void add(int po,int x){
    po+=n;
    data[po].push_back({x,1});
    for(po/=2;po>=1;po/=2){
        set<pii> a;
        for(auto x:data[po*2]){
            for(auto y:data[po*2+1]){
                if(x.first == y.first){
                    data[po].push_back({x.first,x.second+y.second});
                    a.insert(x.first);
                }else{
                    data[po].push_back(x);
                    data[po].push_back(y);
                }
            }
        }
        sort(data[po].begin(),data[po].end());
    }
}

int kitt(int l,int r){
    int ans = 0;
    while(l<=r){
        if(l%2==1){

            l++;
        }
        if(r%2==0){

            r++;
        }
        l/=2;
        r/=2;
    }
    return ans;
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        add(i,x);
    }
    for(int i=0;i<(n*2);i++){
        cout<<i<<" ** \n";
        for(auto x:data[i]){
            cout<<x.first<<" "<<x.second<<"\n";
        }
        cout<<"\n";
    }
}
