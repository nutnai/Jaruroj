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
        bool end = false;
        int n;
        scanf("%d",&n);
        int data[n];
        int base[n];
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            data[i] = x;
            now[x] = i;
            base[i] = x;
        }
        sort(base,base+n);
        int I;
        int J;
        for(int i=0;i<n;i++)
        {
            I = i+1;
            if(data[i] != base[i])
            {
                int tempdata = data[i];
                int tempnow = now[base[i]];
                J = tempnow+1;
                data[i] = base[i];
                now[base[i]] = i;

                now[tempdata] = tempnow;
                data[tempnow] = tempdata;
            }
            else
            {
                J = I;
                end = true;
                for(int j=0;j<n-1;j++)
                {
                    if(data[j]>data[j+1])
                    {
                        end = false;
                    }
                }
            }
            if(!end || sum == 0)
            {
                sum += J - I + 1;
            }else break;
            
            /*cout<<"\n"<<i<<" | ";
            for(int j=0;j<n;j++)
            {
                cout<<data[j]<<" ";
            }
            cout<<"("<<I<<","<<J<<" = "<<J-I+1<<") [ ";
            for(int j=1;j<8;j++)
            {
                cout<<now[j]<<" ";
            }
            cout<<"]";*/
            
        }
        cout<<"Case #"<<t<<": "<<sum<<"\n";
    }
}