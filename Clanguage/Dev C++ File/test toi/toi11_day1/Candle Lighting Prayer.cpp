#include <bits/stdc++.h>
using namespace std;

bool ka[2002][2002];
int k=0;
stack<pair<int,int>> v;

void kit(int i,int j) {
    ka[i][j]=false;
    if(ka[i+1][j]){
        kit(i+1,j);
    }
    if(ka[i][j+1]){
        kit(i,j+1);
    }
    if(ka[i+1][j+1]){
        kit(i+1,j+1);
    }
    if(ka[i-1][j]){
        kit(i-1,j);
    }
    if(ka[i][j-1]){
        kit(i,j-1);
    }
    if(ka[i-1][j-1]){
        kit(i-1,j-1);
    }
    if(ka[i-1][j+1]){
        kit(i-1,j+1);
    }
    if(ka[i+1][j-1]){
        kit(i+1,j-1);
    }
}

int main() {
    int m,n;
    scanf("%d%d",&n,&m);
    char c;
    for(int i=1; i<=n; i++) {
        scanf("%c",&c);
        for(int j=1; j<=m; j++) {
            scanf("%c",&c);
            int x=c-'0';
            if(x==1) {
                ka[i][j]=true;
                v.push({i,j});
            }

        }
    }
    while(!v.empty()) {
        int x=v.top().first;
        int y=v.top().second;
        if(ka[x][y]){
            kit(x,y);
            k++;
        }
        v.pop();
    }
    cout<<k;
}
