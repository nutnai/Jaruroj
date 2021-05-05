#include <bits/stdc++.h>
using namespace std;

int data[11][11];
bool stan[11];
int n,ans=-2e9,sum;
list<pair<int,int>> temp,v;

void kit(int in) {
    if(in>n) {
        if(ans<sum) {
            ans=sum;
            v=temp;
        }
    } else
        for(int i=1; i<=n; i++) {
            if(stan[i]==false) {
                stan[i]=true;
                sum+=data[in][i];
                temp.push_back(make_pair(in,i));
                kit(in+1);
                sum-=data[in][i];
                stan[i]=false;
                temp.pop_back();
            }
        }

}

int main() {
    scanf("%d",&n);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            scanf("%d",&data[i][j]);
        }
    }

    kit(1);
    cout<<ans<<"\n";
    for(int i=1; i<=n; i++) {
        cout<<get<0>(v.front())<<" "<<get<1>(v.front())<<"\n";
        v.pop_front();
    }

}
