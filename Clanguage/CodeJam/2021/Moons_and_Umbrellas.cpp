#include <bits/stdc++.h>
using namespace std;

int X,Y;

long kid(string input,int po)
{
    if(input[po] == '?')
    {
        
    }
    if(input[po-1] != input[po])
    {

    }
}

int main()
{
    int time;
    scanf("%d",&time);
    for(int t=1;t<=time;t++)
    {
        scanf("%d%d",&X,&Y);
        string input;
        cin>>input;
        cout<<"Case #"<<t<<": "<<kid(input,1);
    }    
}