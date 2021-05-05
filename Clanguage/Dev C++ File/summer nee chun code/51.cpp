#include <stdio.h>

int n;
double a=0,b=0,c=0;



int main(){
	scanf("%d",&n);
	double c[n];
	for(int i=0;i<n;i++){
		scanf("%lf",&c[i]);
		a=a+c[i];
	}
	for(int i=0;i<n;i++){
		if(c[i]<c[i+1]){
			double tmp=c[i];
			c[i]=c[i+1];
			c[i+1]=tmp;
			i--;
		}
	}
	
	for(int i=0;i<n;i++){
		printf("%lf\n",c[i]);
	}
}
