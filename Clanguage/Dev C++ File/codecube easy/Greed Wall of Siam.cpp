#include <bits/stdc++.h>
using namespace std;

int ka[100000001];

int main()
{
    int n,k;
    vector<int> v;
    int minn=2e9;
    int maxx=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&ka[i]);
        minn=min(minn,ka[i]);
        maxx=max(maxx,ka[i]);
    }
    for(int i=2;i<=minn;i++){
        if(minn%i==0){
            v.push_back(i);
        }
    }
    if(!v.empty()){
            int
        for(int i)
    }else k=1;
}
