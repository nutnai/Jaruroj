#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k,n,m,q;
    scanf("%d%d%d",&k,&n,&m);
    int data[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&data[i][j]);
        }
    }
    scanf("%d",&q);
    for(int i=0;i<n;i++){
            int c=0;
        for(int j=0;j<m;j++){
            if(data[i][j]==q){
                c++;
            }
        }
    if(c==0){
        cout<<i+1;
        return 0;
    }
    }
}
