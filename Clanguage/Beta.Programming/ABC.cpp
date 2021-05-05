#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[3];
    for(int i=0;i<3;i++)
    {
        scanf("%d",&arr[i]);
    }   
    sort(arr,arr+3);
    string s;
    cin>>s;
    for(auto x:s)
    {
        if(x == 'A')cout<<arr[0];
        else if(x == 'B')cout<<arr[1];
        else if(x == 'C')cout<<arr[2];
        cout<<" ";
    }
}