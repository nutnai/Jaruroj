#include <bits/stdc++.h>
using namespace std;

long long check(bool c[][3],int i)
{
    if(c[1+i][0]){//1
        if(c[i][1]){//3
            if(c[2+i][1]){//6
                if(c[i+1][1]){//8
                    if(c[i][2]){//9
                        return 8;
                    }else return 9;
                }else return 0;
            }else if(c[i][2]){//7
                return 6;
            }else return 5;
        }else if(c[1+i][2]){//4
        if(c[i][2]){//5
            return 2;
        }else return 3;
        }else return 7;
    }else if(c[i][1]){//2
        return 4;
    }else return 1;
}

int main()
{
    int m,n;
    long long a=0,b=0;
    char c;
    scanf("%d%d%c",&m,&n,&c);
    bool up[m*3][3],down[n*3][3];

    for(int i=0;i<3;i++){
            for(int j=0;j<m*3;j++){
                scanf("%c",&c);
        switch(c)
        {
        case ' ':up[j][i]=false;
            break;
        default :up[j][i]=true;
            break;
        }
            }
            scanf("%c",&c);
    }

    for(int i=0;i<3;i++){
            for(int j=0;j<n*3;j++){
                scanf("%c",&c);
        switch(c)
        {
        case ' ':down[j][i]=false;
            break;
        default :down[j][i]=true;
            break;
        }
            }
                scanf("%c",&c);
    }
    /////////////////////////////////////////////////////////
    for(int i=0;i<m;i++){
        int x=m-i-1;
        int z=(pow(10,x)+0.5);
        a+=check(up,i*3) * z;
    }
    for(int i=0;i<n;i++){
        int x=n-i-1;
        int z=(pow(10,x)+0.5);
        b+=check(down,i*3) * z;
    }
    cout<<a+b;
}
