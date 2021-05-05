#include <bits/stdc++.h>
using namespace std;

int n;

struct output
{
    int ans;
    vector<int> path;
};
output kid(int moneyleft,int moneytype[])
{
    output x;
    if(moneyleft == 0)
    {
        x.ans = 0;
        return x;
    }
    int ans = 2e9;
    int path = 0;
    for(int i = 0 ; i < n ; i ++)
    {
        if(moneyleft >= moneytype[i])
        {
            path = moneytype[i];
            x.path.push_back(path);
            output d = kid(moneyleft - moneytype[i],moneytype);
            if(ans >= d.ans+1)
            {
                ans = d.ans+1;
            }
        }
    }
    x.ans = ans;
    return x;
}

int main()
{
    int moneyleft;
    printf("Money type : ");
    scanf("%d",&n);
    int moneytype[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&moneytype[i]);
    }
    printf("Money Left : ");
    scanf("%d",&moneyleft);
    output x = kid(moneyleft,moneytype);
    if(x.path.size() == 0)
    {
        cout<<"Not have Answer";
        return 0;
    }
    cout<<"Answer is : "<<x.ans<<"\npath : ";
    for(auto o : x.path)
    {
        cout<<o<<" ";
    }

}
/*
7
5 4 3 1

8
6 5 3 1

14
8 7 4 1
*/