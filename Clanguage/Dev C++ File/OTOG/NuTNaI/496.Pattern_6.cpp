#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
            int a=0;
        for(int j=0;j<n;j++){
            if(j<=i){
                    a++;
            if(a%2!=0)
                cout<<"*";
                else cout<<"-";
            }
        }
        cout<<"\n";
    }
}
