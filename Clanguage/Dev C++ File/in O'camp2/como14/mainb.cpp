#include <bits/stdc++.h>
using namespace std;


int main()
{
    int testcase,node,x,y;
    scanf("%d",&testcase);

    for(int test=0; test<testcase; test++) {
        scanf("%d",&node);
        bool stop=false;
        vector<pair<int,int>> grid[node+1];
        int ans[node+1];

        for(int i=2; i<=node; i++) {
            ans[i]=2e9;
        }
        ans[1]=0;

        while(true) {
            scanf("%d %d",&x,&y);
            if(x==-1 && y==-1) {
                break;
            }
            grid[x].push_back(make_pair(y,0));
        }

        for(int i=1; i<=node-7; i++) {
            if(grid[i].empty()) {
                for(int j=1; j<=6; j++) {
                    grid[i].push_back(make_pair(i+j,1));
                }
            }
        }
        for(int i=node-6; i<=node; i++) {
            if(grid[i].empty())
                for(int j=1; j<=node-i; j++) {
                    grid[i].push_back(make_pair(i+j,1));
                }
        }

        while(stop==false) {
            stop=true;
            for(int i=1; i<=node; i++) {
                for(int j=0; j<grid[i].size(); j++) {
                    int tonode = grid[i][j].first;
                    int  weight = grid[i][j].second;

                    if(ans[tonode] > weight+ans[i]) {
                        ans[tonode] = weight+ans[i];
                        stop=false;
                    }
                }
            }
        }
        if(ans[node]!=2e9) {
            cout<<ans[node]<<"\n";
        } else {
            cout<<"-1"<<"\n";
        }
        for(int i=0; i<=node; i++) {
            grid[i].clear();
            ans[i]=2e9;
        }

    }
}
