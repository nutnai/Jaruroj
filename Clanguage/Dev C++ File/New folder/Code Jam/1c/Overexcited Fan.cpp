#include <bits/stdc++.h>
using namespace std;

using pii=pair<int,int>;

int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        int x,y;
        scanf("%d%d",&y,&x);
        int walk=0;
        vector<pii> v;
        string s;
        cin>>s;
        int rob=s.size();

        v.push_back({abs(x)+abs(y),walk});
        walk++;
        for(int i=0;i<rob;i++){
            switch(s[i]){
            case 'N':x++;
                break;
            case 'E':y++;
                break;
            case 'S':x--;
                break;
            case 'W':y--;
                break;
            }
        v.push_back({abs(x)+abs(y),walk});
        walk++;
        }
        cout<<"Case #"<<t<<": ";
        bool check=true;
        for(auto o:v){
            int f=o.first;
            int s=o.second;
            if(f<=rob && f<=s){
                cout<<s;
                check=false;
                break;
            }
        }
        if(check)
            cout<<"IMPOSSIBLE";

        cout<<"\n";
    }
}
