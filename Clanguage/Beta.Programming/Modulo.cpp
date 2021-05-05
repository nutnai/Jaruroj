#include <bits/stdc++.h>
using namespace std;

bool in[43];

int main()
{
    int ans = 0;
    for(int i=0;i<10;i++)
    {
        int x;
        scanf("%d",&x);
        int kid = x%42;
        if(!in[kid])
        {
            in[kid] = true;
            ans++;
        }
    }
    cout<<ans;
}