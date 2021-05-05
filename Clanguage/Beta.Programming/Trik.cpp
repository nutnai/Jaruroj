#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool arr[3] = {1,0,0};
    string s;
    bool temp;
    cin>>s;
    for(auto x:s)
    {
        if(x == 'A')
        {
            temp = arr[0];
            arr[0] = arr[1];
            arr[1] = temp;
        }
        else if(x == 'B')
        {
            temp = arr[1];
            arr[1] = arr[2];
            arr[2] = temp;
        }
        else
        {
            temp = arr[0];
            arr[0] = arr[2];
            arr[2] = temp;
        }
    }
        for(int i=0;i<3;i++)
        {
            if(arr[i])
            {
                cout<<i+1;
                return 0;
            }
        }
}