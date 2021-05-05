#include <bits/stdc++.h>
using namespace std;

int main()
{
    int year;
    map<int,pair<int,int>> m;
    for(int i=3;i<=24;i++)
        m[i]=make_pair(0,0);

    m[1]=make_pair(2,1);
    m[2]=make_pair(4,2);
    while(true){
        scanf("%d",&year);
        if(year==-1)
            return 0;
        if(m[year].first!=0)
            cout<<m[year].first<<" "<<m[year].first+m[year].second+1<<"\n";
        else{
            for(int i=3;i<=year;i++){
                m[i].first=m[i-1].first+m[i-1].second+1;
                m[i].second=m[i-1].first;
            }
            cout<<m[year].first<<" "<<m[year].first+m[year].second+1<<"\n";
        }
    }
}
