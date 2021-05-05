#include <stdio.h>

long long N,a=0,b=0;


main(){
	scanf("%lld",&N);
	a=N/374;
	if(N%374>276){
		b=12;
	}else{
		b=(N%374)/23;
	if((b*23)+(a*374)<N){
		b++;
	}
	}
	
	printf("%lld",(a*84)+(b*7));
}
