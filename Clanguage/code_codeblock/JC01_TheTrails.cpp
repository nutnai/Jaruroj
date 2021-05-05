#include <bits/stdc++.h>
using namespace std;

int tree[200001];
int high[200001];
int n,m;

void add(int po,int x){
    po+=n;
    tree[po]+=x;
    for(po/=2;po>=1;po/=2){
        tree[po] = tree[po*2] + tree[po*2+1];
    }
}

void addh(int po,int x){
    po+=n;
    high[po] = max(high[po],x);
    for(po/=2;po>=1;po/=2){
        high[po] = max(high[po*2] , high[po*2+1]);
    }
}

int findh(int l,int r){
    l+=n;
    r+=n;
    int ans = 0;
    while(l<=r){
        if(l % 2 == 1){
            ans = max(ans,high[l]);
            l++;
        }
        if(r%2==0){
            ans = max(ans,high[r]);
            r--;
        }
        l/=2;
        r/=2;
    }
    return ans;
}

int sum(int l,int r){
    l+=n;
    r+=n;
    int ans = 0;
    while(l <= r){
        if(l % 2 == 1){
            ans+=tree[l];
            l++;
        }
        if(r%2==0){
            ans+=tree[r];
            r--;
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
        addh(i,x);
    }
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        add(i,x);
    }
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        cout<<findh(x,y)<<" "<<sum(x,y)<<"\n";
    }
}
