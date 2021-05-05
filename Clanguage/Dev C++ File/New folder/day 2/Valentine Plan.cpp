#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,x1,x2,wox,woy;
    float ans=1001.0,x3;
    scanf("%d%d",&n,&m);
    pair<int,int> man[n];
    for(int i=0;i<n;i++){
        scanf("%d%d",&get<0>(man[i]),&get<1>(man[i]));
    }
    for(int i=0;i<m;i++){
        scanf("%d%d",&wox,&woy);
        for(int j=0;j<n;j++){
                x1=pow(get<0>(man[j])-wox,2);
                x2=pow(get<1>(man[j])-woy,2);
                x3=sqrt(x1+x2);
            if(x3<ans)
                ans=x3;
        }
    }
    printf("%.3f",ans);

}
