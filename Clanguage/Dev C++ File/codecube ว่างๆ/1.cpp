#include <stdio.h>

main(){
	long long a,num=1;
	scanf("%lld",&a);
	if((a<1)&&(a>30)){
		return 0;
	}
	for(a;a>0;a--){
		num=num+num*3;
	}
	printf("%lld",num);
}
