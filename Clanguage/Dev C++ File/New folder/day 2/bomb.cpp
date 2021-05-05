#include <bits/stdc++.h>
using namespace std;

bool data[1001][1001];
int main() {
    int y,b;
    scanf("%d%d",&y,&b);
    int ans[b];
    for(int i=1; i<=y; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        data[x][y]=true;
    }
    for(int a=0; a<b; a++) {
        int x,y,z;
        ans[a]=0;
        scanf("%d%d%d",&x,&y,&z);
        for(int i=x-z;i<=x+z;i++){
            for(int j=y-z;j<=y+z;j++){
                    if(i<0||j<0||i>1000||j>1000)
                    continue;
                if(data[i][j]==true){
                    ans[a]++;
                    data[i][j]=false;
                }
            }
        }
    }
    for(int i=0;i<b;i++){
        cout<<ans[i]<<"\n";
    }
}
