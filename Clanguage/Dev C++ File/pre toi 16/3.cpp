#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k,q;
    scanf("%d%d%d",&n,&k,&q);
    int ka[n+1][k+1];
    for(int i=1; i<=n; i++) {
        int x;
        if(i==1) {
            scanf("%d",&x);
            if(x<=k) {
                ka[i][x]++;
            }
        } else {
            scanf("%d",&x);
            if(x<=k) {
                ka[i][x]++;
            }
            for(int l=1; l<=k; l ++) {
                ka[i][l]+=ka[i-1][l];
            }
        }

    }
    for(int i=1; i<=q; i++) {
        int st,fn;
        scanf("%d%d",&st,&fn);
        if(st>1) {
            st--;
        }
        if(fn-st>=k) {

            bool check=true;
            for(int j=1; j<=k; j++) {
                if(ka[fn][j]-ka[st][j]<1) {
                    check=false;
                    break;
                }
            }
            if(check)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        } else
            cout<<"No\n";
    }

}
