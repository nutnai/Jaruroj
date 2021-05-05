#include <stdio.h>

int n;

main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		for(int j=1;j<=n*2+1;j++){
			if(i>=j||i+j>=n*2+2){
			printf("*");	
			}else
			printf("-");
		}
		printf("\n");
	}
	
	int m=n/2;
	m=(n%2==1)? m:m-1;
	for(int i=1;i<=m;i++){
		printf("-");
	}
	for(int i=1;i<=n-m;i++){
		printf("*");
	}
	printf("@");
	for(int i=1;i<=n-m;i++){
		printf("*");
	}
	for(int i=1;i<=m;i++){
		printf("-");
	}
	printf("\n");
	
	for(int i=1;i<n;i++){
		for(int j=1;j<=n*2+1;j++){
			if(j<=n-i||j>=n+i+2){
			printf("*");	
			}else
			printf("-");
		}
		printf("\n");
	}
}
