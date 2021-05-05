#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k,n;
    priority_queue<double,vector<pair<double,int>>,greater<pair<double,int>>> data;
    scanf("%d",&k);
    int type[k];

    for(int i=0;i<k;i++){
            int kg,laka;
        scanf("%d%d",&laka,&kg);
        type[i]=kg;
        double z=(laka*1.0)/kg;
        data.push(make_pair(z,i));
    }
    scanf("%d",&n);
    double ans[n];

    for(int i=0;i<n;i++){
            ans[i]=0;
            int x;
        scanf("%d",&x);
        while(x!=0){
                int y=get<1>(data.top());
            if(type[y]!=0){
                if(x<=type[y]){
                    type[y]-=x;
                    ans[i]+=x*get<0>(data.top());
                    x=0;
                }else{
                    x-=type[y];
                    ans[i]+=type[y]*get<0>(data.top());
                    data.pop();
                }
            }else data.pop();
        }
    }
    for(int i=0;i<n;i++){
        printf("%.3f\n",ans[i]);
    }
}
