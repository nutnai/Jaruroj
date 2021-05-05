#include <stdio.h>

int n,k,sum,check;

main(){
	scanf("%d%d",&n,&k);
	int ch[n+1];
	for(int i=1;i<=n;i++){
		scanf("%d",&ch[i]);
		if(i!=k){
			sum=sum+ch[i]/2+ch[i]%2;
		}
	}
	scanf("%d",&check);
	if(sum<check){
		printf("%d",check-sum);
	}else printf("Chi So Cute >//<'");
}
