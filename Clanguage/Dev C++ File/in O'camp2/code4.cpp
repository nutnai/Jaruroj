#include <bits/stdc++.h>
using namespace std;

int n,m,x,y,z,e,r;

char f;

int main(){
    cin>>n>>m;
    vector<int> data[n+2];
    for(int i=1;i<=n;i++){
    	data[i].push_back(0);
	}
    for(int i=1;i<=m;i++){
        cin>>f;
        switch(f){
    case '=' :cin>>x>>y;
            data[x].push_back(y);
            e=x;
            break;
    case '+' :cin>>x>>y>>z;
            data[z].push_back(data[x].back()+data[y].back());
            e=z;
            break;
    case '-' :cin>>x>>y>>z;
            data[z].push_back(data[x].back()-data[y].back());
            e=z;
            break;
    case 'C' :cin>>x>>y;
            data[y].push_back(data[x].back());
            e=y;
            break;
    case 'P' :cin>>x;
            data[n+1].push_back(data[x].back());
            r++;
            e=0;
            break;
    case 'U' :cin>>x;
    		for(int j=1;j<=x;j++){
    			for(int k=1;k<=n;k++){
    				data[k].pop_back();
				}
			}
			e=0;
			break;
        }
        if(e!=0){
        	for(int j=1;j<=n;j++){
        	if(e!=j){
        		data[j].push_back(data[j].back());
			}
		}
		}
        
    }
    for(int i=0;i<r;i++){
    	cout<<data[n+1][i]<<"\n";
	}
}


