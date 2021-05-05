#include <stdio.h>
#include <string.h>

int n=3,x,c;
char o[2][100];
main(){
	scanf("%s",&o[1]);
	c=strlen(o[1]);
	c%n>0?c++:0;
	for(int j=1;j<=c;j++){
		for(int i=0;i<n;i++){
			printf("%c",o[1][x]);
			x++;
		}
		for(int i=1;i<=n-1;i++){
			printf(" ");
		}
		
	}
}
