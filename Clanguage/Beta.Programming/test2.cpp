#include <bits/stdc++.h>
using  namespace std;

vector<int> kin[100001];
bool check[100001],start[100001];
vector<int> ans;

void print(int now){
    int x=kin[now].size();
    for(int i=0;i<x;i++){
        print(kin[now][i]);
    }
    for(int i=0;i<x;i++){
            int y=kin[now][i];
            if(!check[y]){
                    check[y]=true;
                 ans.push_back(y);
            }
    }

}

int main()
{
    int n,m,c=0;
    scanf("%d%d",&n,&m);

    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        kin[b].push_back(a);
        start[a]=true;
    }
    for(int i=1;i<=n;i++){
        if(!start[i]){
            kin[0].push_back(i);
            c++;
        }

    }
    if(c==0){
        cout<<"No\n";
        return 0;
    }

    cout<<"Yes\n";
    print(0);
    while(!ans.empty()){
        cout<<ans.back()<<" ";
        ans.pop_back();
    }

}


