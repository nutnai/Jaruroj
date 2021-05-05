#include <bits/stdc++.h>
using namespace std;

int nub[5],data[101][101];

int main() {
    int n,k,nextx,nexty;
    char c;
    list<int> win;
    list<char> path[5];
    scanf("%d%d",&n,&k);
    pair<int,int> stay[5];

    data[1][1]=4;
    data[n][1]=3;
    data[1][n]=1;
    data[n][n]=2;
    stay[1]=make_pair(1,n);
    stay[2]=make_pair(n,n);
    stay[3]=make_pair(n,1);
    stay[4]=make_pair(1,1);

    for(int i=1; i<=4; i++) {
        for(int j=1; j<=k; j++) {
            scanf(" %c",&c);
            path[i].push_back(c);
        }
    }
    for(int i=1; i<=k; i++) {
        for(int j=1; j<=4; j++) {
            int ch=0;
            c=path[j].front();
            switch(c) {
            case 'N':
                nextx = stay[j].first - 1;
                nexty = stay[j].second;
                break;
            case 'W':
                nextx = stay[j].first;
                nexty = stay[j].second - 1;
                break;
            case 'S':
                nextx = stay[j].first + 1;
                nexty = stay[j].second;
                break;
            case 'E':
                nextx = stay[j].first;
                nexty = stay[j].second + 1;
                break;
            }
            if(nextx < 1 || nextx > n)
                ch=1;
            if(nexty < 1 || nexty > n)
                ch=1;
            for(int check=1; check<=4; check++) {
                if(nextx == stay[check].first && nexty == stay[check].second)
                    ch=1;
            }
            if(ch==0) {
                stay[j]=make_pair(nextx,nexty);
                data[nextx][nexty]=j;
            }
            path[j].pop_front();

        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(data[i][j]==0) {
                cout<<"No";
                return 0;
            }
            nub[data[i][j]]++;
        }
    }
    int top=max(nub[1],max(nub[2],max(nub[3],nub[4])));
    for(int i=1; i<=4; i++) {
        if(top==nub[i])
            win.push_back(i);
    }
    cout<<win.size()<<" "<<top<<"\n";
    while(!win.empty()) {
        cout<<win.front()<<"\n";
        win.pop_front();
    }
}
