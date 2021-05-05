#include <bits/stdc++.h>
using namespace std;

int now[102];

int main()
{
    int time;
    scanf("%d",&time);
    int sum = 0;
    for(int t=1;t<=time;t++)
    {
        sum = 0;
        int n;
        scanf("%d",&n);
        int data[n];
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            data[i] = x;
        }
        for(int i=0;i<n-1;i++)
        {
            int small = 200;
            int po = i;
            for(int j=i;j<n;j++)
            {
                if(small > data[j])
                {
                    small = data[j];
                    po = j;
                }
            }
            reverse(data+i,data+po+1);
            sum += (po+1) - (i+1) + 1;
            
        }
        cout<<"Case #"<<t<<": "<<sum<<"\n";
    }
}