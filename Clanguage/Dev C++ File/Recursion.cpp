#include <stdio.h>
int n,re;

int sum(int x){
	if(x==0)
	    return 0;	
	else return (x+sum(x-1));
} 
main(){
	scanf("%d",&n);
	sum(n);
	printf("%d",sum(n));
}
