#include <bits/stdc++.h>
using namespace std;

int main() {
    int m,n,j;
    int ans=0,k=1;
    scanf("%d%d",&n,&m);
    bool ka[n][m][2];
    int rob=min(n,m)-1;
    char c;
    scanf("%c",&c);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%c",&c);
            ka[i][j][k]=c-'0';
            if(ka[i][j][k])
                ans++;
        }
        scanf("%c",&c);
    }
    cout<<ans<<"\n";
    bool ansss=false;
    for(int i=0; i<rob; i++) {
        if(ansss){
        cout<<"0\n";
    } else {
        ans=0;
        if(k==1)
                j=2;
            else
                j=1;
            n--;
            m--;
            for(int x=0; x<n; x++) {
                for(int y=0; y<m; y++) {
                    ka[x][y][j]=(ka[x+1][y+1][k] && ka[x][y+1][k] && ka[x+1][y][k] && ka[x][y][k]);
                    if(ka[x][y][j])
                        ans++;
                }
            }
            cout<<ans<<"\n";
            if(ans==0)
                ansss=true;
            if(k==2)
                k=1;
            else
                k=2;
        }

    }
}
