#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h,m;
    scanf("%d%d",&h,&m);
    if(m<45){
        m+=60;
        h-=1;
    }
    if(h<0)
        h=23;
    cout<<h<<" "<<m-45;
}
