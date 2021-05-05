#include <stdio.h>

int N,M;

main(){
	scanf("%d %d",&N,&M);
	int ka[N+1];
	float num[N+1],a;
	for(int q=1;q<=N;q++){
		scanf("%d",&ka[q]);
	}
	for(int i=1;i<=N-M+1;i++){
		a=0;
		for(int w=i;w<=i+M-1;w++){
			a=a+ka[w];
		}
		a=a/M;
		num[i]=a;
	}
	int f=0;
	printf("%d\n",N-M+1);
	for(int i=1;i<=N-M+1;i++){
		f++;
		printf("%f ",num[i]);
		if(f==3){
			printf("\n");
			f=0;
		}
	}
}
