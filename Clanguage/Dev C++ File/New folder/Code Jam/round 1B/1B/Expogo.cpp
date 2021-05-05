#include <bits/stdc++.h>
using namespace std;

int main() {
    int test,r,s;
    scanf("%d",&test);
    for(int t=1; t<=test; t++) {
        scanf("%d%d",&r,&s);
        int ii=r*(s-1);
        vector<int> a,b;
        for(int i=ii; i>=s; i--) {
            a.push_back(i);
        }
        int temp=1;
        for(int j=r*s-ii-1; j>=1; temp++) {
            if(temp==s) {
                j--;
                temp=0;
            }
            b.push_back(j);
        }
        cout<<"Case #"<<t<<": "<<a.size()<<"\n";
        int rob=a.size();
        for(int i=0; i<rob; i++) {
            cout<<a[i]<<" "<<b[i]<<"\n";
        }
    }
}
