#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    int no,lu,sp;
    map<int,int> k;
    scanf("%d%d",&n,&m);
    list<int> v[m+1];
    for(int i=0; i<n; i++) {
        scanf("%d %d %d",&no,&lu,&sp);
        v[lu].push_back(no);
        k[no]=sp;
    }
    bool stop=false;
    int z=0;
    while(!stop) {
        stop=true;
        int ansno,anssp=-1;
        for(int i=z; i<=m; i++) {
            if(!v[i].empty()) {
                stop=false;
                int a=v[i].front();
                if(anssp<k[a]) {
                    anssp=k[a];
                    ansno=a;
                }
                v[i].pop_front();
            }
        }
        if(!stop)
            cout<<ansno<<"\n";
            else return 0;
        while(v[z].empty() && v[z+1].empty())//!  แก้ปัญหา T แบบสิ้นคิดสุดๆ
            z++;
    }
}
