#include <stdio.h>

main(){
	char a[3][20];
	for(int i;i<=3;i++){
		
		scanf("%c",&a[i][j]);
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("%c",a[i][j]);
		}
	}
}
