#include <stdio.h>

char num1[9][1112],num2[9][1112];
int i,j,num11[1112],num22[1112],sum[1112],n1,n2,nn;
main(){
	////////////////////////////num1
	for(i=1;i<1112;i++){
		n1++;
		for(j=0;j<9;j++){
			scanf("%c",&num1[j][i]);
			if(num1[j][i]=='\n'){
				break;
			}
		}
		if(num1[j][i]=='\n'){
				break;
			}
	}
	///////////////////////////////////num2
	for(i=1;i<1112;i++){
		n2++;
		for(j=0;j<9;j++){
			scanf("%c",&num2[j][i]);
			if(num2[j][i]=='\n'){
				break;
			}
		}
		if(num2[j][i]=='\n'){
				break;
			}
	}
	/////////////////////////////////////char to int
	n1>n2?nn=n1:nn=n2;
	for(i=1;i<nn;i++){
		int x=1;
		for(j=0;j<9;j++){
			num11[i]=num11[i]+((int)num1[j][i]*x);
			num22[i]=num22[i]+((int)num2[j][i]*x);
			x*=10;
		}
		if(num11[i]>=1000000000){
				num11[i]-=1000000000;
				num11[i-1]++;
			}
			if(num22[i]>=1000000000){
				num22[i]-=1000000000;
				num22[i-1]++;
			}
	}
	////////////////////////////////////plus
	for(i=1;i<=nn+1;i++){
		sum[i]=num11[i]+num22[i];
		if(sum[i]>=1000000000){
				sum[i]-=1000000000;
				sum[i-1]++;
			}
	}
	////////////////////////////////////print
	sum[0]==0?i=1:i=0;
	for(i;i<nn;i++){
		printf("%d",sum[i]);
	}
}
