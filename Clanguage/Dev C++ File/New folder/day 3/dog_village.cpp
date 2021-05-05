#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int village[n][m];
    vector<pair<int,int>> zombie,result;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d",&village[i][j]);
            if(village[i][j]==0)
                zombie.push_back(make_pair(i,j));
        }
    }

    bool stop=false;
    int day=0;
    while(!stop)
    {
        stop=true;
        day++;

        for(int i=0; i<zombie.size(); i++)
        {
            int x=get<0>(zombie[i]);
            int y=get<1>(zombie[i]);
            if(x-1>=0) //! up
            {
                if(village[x-1][y]>day&&
                        village[x-1][y]!=0)
                {
                    village[x-1][y]=0;
                    stop=false;
                    result.push_back(make_pair(x-1,y));
                }
            }
            if(y+1<m) //! right
            {
                if(village[x][y+1]>day&&
                        village[x][y+1]!=0)
                {
                    village[x][y+1]=0;
                    stop=false;
                    result.push_back(make_pair(x,y+1));
                }
            }
            if(x+1<n) //! down
            {
                if(village[x+1][y]>day&&
                        village[x+1][y]!=0)
                {
                    village[x+1][y]=0;
                    stop=false;
                    result.push_back(make_pair(x+1,y));
                }
            }
            if(y-1>=0) //! left
            {
                if(village[x][y-1]>day&&
                        village[x][y-1]!=0)
                {
                    village[x][y-1]=0;
                    stop=false;
                    result.push_back(make_pair(x,y-1));
                }
            }
        }
        while(!result.empty()){
            zombie.push_back(make_pair(get<0>(result.back()),get<1>(result.back())));
            result.pop_back();
        }
    }
    cout<<(n*m)-zombie.size();
}
