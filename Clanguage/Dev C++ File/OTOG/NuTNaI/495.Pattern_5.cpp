#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,a;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        n%2==0?a=0:a=1;
        for(int j=0;j<n;j++){
            if(j<n-i-1)
                cout<<"-";
         else{
             a++;
         if(a%2==0)
                cout<<"^";
                else cout<<"*";
         }
        }
        cout<<"\n";
    }
}
