#include <bits/stdc++.h>
using namespace std;

int ans = 0;

void check(bitset<14> bit)
{
    int c = 0;
    for(int i=0;i<14;i++)
    {
        if(bit[i])
        {
            c++;
            if(c == 3)
            {
                ans++;
                return;
            }
        }
        else
        {
            c = 0;
        }
    }
}

int main()
{
    for(int i=1;i<=10000;i++)
    {
        bitset<14> bit(i);
        check(bit);
    }
    cout<<ans;
}