#include <stdio.h>

main(){
	int x;
	scanf("%d",&x);
	char ans[x][20];
	for(int i=0;i<x;i++){
		for(int j;j<=20;j++){
			scanf("%c",&ans[i][j]);
			if(ans[i][j]==' '){
				break;
			}
		}
	}
}
