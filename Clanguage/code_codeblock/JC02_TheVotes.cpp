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
        set<int> a[n];
        vector<pii> need;
        for(auto x:data[po*2]){
            for(auto y:data[po*2+1]){
                if(x.first == y.first){
                    data[po].push_back({x.first,x.second+y.second});
                    a[po].insert(x.first);
                }else{
                    need.push_back(x);
                    need.push_back(y);
                }
            }
        }
        for(auto x:need){
            if(a[po].find(x.first)==a[po].end()){
                data[po].push_back(x);
                a[po].insert(x.first);
            }
        }
        sort(data[po].begin(),data[po].end());
    }
}

int kitt(int l,int r){
    int ans = 0;
    vector<pii> check;
    while(l<=r){
        if(l%2==1){
            for(auto x:data[l]){
                check.push_back(x);
            }
            l++;
        }
        if(r%2==0){
            for(auto x:data[r]){
                check.push_back(x);
            }
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
    /*for(int i=0;i<(n*2);i++){
        cout<<i<<" ** \n";
        for(auto x:data[i]){
            cout<<x.first<<" "<<x.second<<"\n";
        }
        cout<<"\n";
    }*/
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        int num = kitt(x,y);
        cout<<num<<" ";
        if(num>y-x+1){
            cout<<"T\n";
        }else cout<<"F\n";
    }
}
