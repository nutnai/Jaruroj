#include <bits/stdc++.h>
using namespace std;

using tiii = tuple<int,int,int>;

int main() {
    int t;
    scanf("%d",&t);
    for(int nt=1; nt<=t; nt++) {

        int n;
        int velagorn=0;
        int vela[2]= {0,0};
        scanf("%d",&n);
        priority_queue<tiii,vector<tiii>,greater<tiii>> q;
        tuple<int,int,int> qq;
        char ans[n];
        bool c=true;

        for(int i=0; i<n; i++) {
            int x,y;
            scanf("%d%d",&x,&y);
            get<0>(qq)=x;
            get<1>(qq)=y;
            get<2>(qq)=i;
            q.push(qq);
        }
        while(!q.empty()) {
            int velanee=get<0>(q.top());
            int finish=get<1>(q.top());
            int tumnaenk=get<2>(q.top());
            if(vela[0]<=velanee) {
                vela[0]=finish;
            } else if(vela[1]<=velanee) {
                ans[tumnaenk]='J';
                vela[1]=finish;
            } else {
                c=false;
                break;
            }
            q.pop();
        }
        cout<<"Case #"<<nt<<": ";
        if(c) {
            for(int i=0; i<n; i++) {
                cout<<ans[i];
            }
            cout<<"\n";
        } else
            cout<<"IMPOSSIBLE\n";
    }
}
