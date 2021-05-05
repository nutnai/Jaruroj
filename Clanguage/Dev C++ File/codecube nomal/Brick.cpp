#include <bits/stdc++.h>
using namespace std;

int n,m;
int kormoon[21][21];

void print(){
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(kormoon[i][j]==1)
                cout<<".";
            else if(kormoon[i][j]==2)
                cout<<"O";
            else
                cout<<"#";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

int main() {
    string c;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) {
        cin>>c;
        for(int j=0; j<m; j++) {
            if(c[j]=='.')
                kormoon[i][j]=1;
            else {
                kormoon[i][j]=2;
            }
        }
    }

    for(int i=0; i<m; i++) {
        int in;
        scanf("%d",&in);
        for(int z=0; z<in; z++) {
            int k=0;
            while(kormoon[k][i]==1) {
                k++;
            }
            if(k!=0)
            kormoon[k-1][i]=3;
        }
    }
    print();

}
