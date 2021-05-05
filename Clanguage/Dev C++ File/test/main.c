#include <stdio.h>
int n,re;

int sum(int x){
    if(x==1)
        return 1;

    else re=(x+sum(x-1));
        return re;
}
main(){
	scanf("%d",&n);
	printf("%d",sum(n));
}
