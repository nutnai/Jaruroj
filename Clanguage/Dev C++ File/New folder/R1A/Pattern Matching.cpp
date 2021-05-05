#include <bits/stdc++.h>
using namespace std;

int mem[1001][1001];

int kit(int a[],int b[],int i,int j) {
    list<char> ans;
    if(i<1 || j<1)
        return 0;
    if(mem[i][j]>0)
        return mem[i][j];
    if(a[i]==b[j]){
            ans.push_back(a[i]);
        return mem[i][j]=kit(a,b,i-1,j-1)+1;
    }

    else {
        return mem[i][j]=max(kit(a,b,i-1,j),
                             kit(a,b,i,j-1));
    }
}

int main() {
    int t;
    scanf("%d",&t);
    for(int tt=1; tt<=t; tt++) {
        int n;
        scanf("%d",&n);
        list<char> v[n];
        char c;
        scanf("%c",&c);
        for(int i=0; i<n; i++) {
            while(true) {
                scanf("%c",&c);
                if(c=='\n')
                    break;
                v[i].push_back(c);
                }

        }
        list<char> ans=kit(v[0],v[1],v[0].size()-1,v[1].size()-1);
    }
}
