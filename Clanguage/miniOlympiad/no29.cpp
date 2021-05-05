#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long ans = 1;
    for(int i=1;i<=100;i++)
    {
        ans*=3;
        if(mem[ans%2557])
        {
            cout<<"Here !";
        }
        else mem[ans%2557] = true;
        cout<<i<<" = "<<ans%2557<<"\n";
    }
}