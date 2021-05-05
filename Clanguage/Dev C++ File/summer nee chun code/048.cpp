#include <stdio.h>
int n,x,sum,test;
main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d",&x);
		test=test+x;
	}
	for(int i=1;i<=n;i++){
		sum=sum+i;
	}
	printf("%d",sum-test);
}
