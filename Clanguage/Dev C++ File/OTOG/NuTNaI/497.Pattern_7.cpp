#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    if(n%2==1)
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if((i%2==1||j%2==1))//
                cout<<"*";
            else cout<<"-";
        }
        cout<<"\n";
    }
    else {
        for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i%2==1)
                cout<<"*";
            else cout<<"-";
        }
        cout<<"\n";
    }
    }
}
