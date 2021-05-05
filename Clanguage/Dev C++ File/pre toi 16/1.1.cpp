#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k,q;
	scanf("%d%d%d",&n,&k,&q);
	int ka[n+1];
	bool check[n+1];
	for(int i=1;i<=n;i++){
		scanf("%d",&ka[i]);
	}
	for(int i=0;i<q;i++){
		int st,fn,ans=0;
		scanf("%d%d",&st,&fn);
		for(int p=1;p<=k;p++){
			check[p]=false;
		}
		for(int j=st;j<=fn;j++){
			bool x=check[ka[j]];
			if(!x&&ka[j]<=k){
				check[ka[j]]=true;
				ans++;
				if(ans==k)
					break;
			}
		}
		if(ans==k)
			cout<<"YES\n";
		else cout<<"NO\n";
	}


}
