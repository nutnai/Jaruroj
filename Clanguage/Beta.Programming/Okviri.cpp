#include <bits/stdc++.h>
using namespace std;

int n;
string s;

void one()
{
    cout<<"..#..";
    for(int i=2;i<=n;i++)
    {
        if(i%3==0)
        {
            cout<<".*..";
        }
        else
        {
            cout<<".#..";
        }
    }
    cout<<"\n";
}
void two()
{
    for(int i=1;i<=n;i++)
    {
        if(i%3==0)
        {
            cout<<".*.*";
        }
        else
        {
            cout<<".#.#";
        }
    }
    cout<<".\n";
}
void three()
{
    for(int i=1;i<=n+1;i++)
    {
        if(i==n+1)
        {
            if((i-1)%3 == 0)
            {
                cout<<"*";
            }
            else
            {
                cout<<"#";
            }
            break;
        }
        if((i%3==0 || (i-1)%3==0) && i!=1)
        {
            cout<<"*";
        }
        else
        {
            cout<<"#";
        }
        cout<<"."<<s[i-1]<<".";
    }
    cout<<"\n";
}

int main()
{
    cin>>s;   
    n = s.size();
    one();
    two();
    three();
    two();
    one();
}