#include <bits/stdc++.h>
using namespace std;

string s;
int check[5];
bool o;
int u=1,r=2,d=3,l=4,x,y;

int main() {
    cin>>s;
    int n;
    scanf("%d",&n);
    int m=n;
    for
    (int i=0; i<s.size(); i++) {
        switch(s[i]) {
        case 'N':
            x++;
            check[u]++;
            break;
        case 'S':
            x--;
            check[d]++;
            break;
        case 'W':
            y--;
            check[l]++;
            break;
        case 'E':
            y++;
            check[r]++;
        }
    }
    /*if(n==s.size()) {
        cout<<"0";
        return 0;
    }*/
    if(check[u]>check[d])
        o=true;
    if(n==s.size()||(x==0&&y==0)){
        cout<<"0";
        return 0;
    }
    while(n>0) {
        if((x>0)&&check[d]!=0) { //! 1,2,8,up
            x+=2;
            check[d]--;
        } else if((x>0&&y>=0)&&check[l]!=0) { //! 1,2 right
            y+=2;
            check[l]--;
        } else if((x>0&&y<=0)&&check[r]!=0) { //! 1,8 left
            y-=2;
            check[r]--;
        } else if((x==0 && y>0)&&check[l]!=0) { //! 3 right
            y+=2;
            check[l]--;
        } else if((x==0 && y>0&&!o)&&check[d]!=0) { //! 3 up
            x+=2;
            check[d]--;
        } else if((x==0 && y>0&&o)&&check[u]!=0) { //! 3 down
            x-=2;
            check[u]--;
        } else if((x<0)&&check[u]!=0) { //! 4,5,6 down
            x-=2;
            check[u]--;
        } else if((x<0&&y<=0)&&check[r]!=0) { //! 5,6 left
            y-=2;
            check[r]--;
        } else if((x<0&&y>=0)&&check[l]!=0) { //! 4,5 right
            y+=2;
            check[l]--;
        } else if((x==0 && y<0)&&check[r]!=0) { //! 7 left
            y-=2;
            check[r]--;
        } else if((x==0 && y<0&&!o)&&check[d]!=0) { //! 7 up
            x+=2;
            check[d]--;
        } else if((x==0 && y<0&&o)&&check[u]!=0) { //! 7 down
            x-=2;
            check[u]--;
        }
        n--;
    }

    while(m>0){
        if(x>0)
            x--;
        else if(x<0)
            x++;
        else if(y>0)
            y--;
        else if(y<0)
            y++;
        m--;
    }
    cout<<(abs(x)+abs(y))*2;
    return 0;

}
