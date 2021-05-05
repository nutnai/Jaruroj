#include <bits/stdc++.h>
using namespace std;


int main()
{
    int data[10];
    for(int i=1;i<=9;i++)
    {
        scanf("%d",&data[i]);
    }
    for(int i=1;i<=511;i++)
    {
        bitset<9> bit(i);
        int sum = 0;
        int n = 0;
        for(int i=1;i<=9;i++)
        {
            if(bit[i])
            {
                n++;
                sum+=data[i];
            }
            if(sum > 100 || n > 7)
            {
                break;
            }
        }
        if(sum == 100 && n == 7)
        {
            for(int i=1;i<=9;i++)
            {
                if(bit[i])
                {
                    cout<<data[i]<<"\n";
                }
            }
            return 0;
        }
    }
}