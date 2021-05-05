#include <stdio.h>
#include <string.h>

int key,th,tv,set,tst,ts,r,lk,x,l;
char w[1][1000];

void pin(){
	printf("%c",w[0][x]);
			x++;
}

main(){
	scanf("%d",&key);
	scanf("%s",&w[0]);
	int n=strlen(w[0]);
	
	//////////////////////////////////////th
	
	switch(key){
		case 1: th=0; break;
		case 2: th=2; break;
		default :th=2+(3*(key-2)); break;
	}
	
	///////////////////////////////////////tv,set,tst,r,lk
	
	key>2?tv=key-2:tv=0;
	
	set=(key-1)*5;
	
	tst=(key-1)*4;
	tst==0?tst=1:0;
	
	r=(n/tst);
	
	if(key>1){
		lk=1;
		for(int i=1;i<=key-2;i++){
			lk+=2;
		}
	}else lk=0;
	
	///////////////////////////////////////print 1
	
	if(r!=0){
		int ch=0;
		n>(r*tst)+((key*2)-2)?ch++:0;
		for(int i=1;i<=(n/tst)+ch;i++){
		for(int j=1;j<=key;j++){
			pin();
		}
		for(int j=1;j<=tv;j++){
			printf(" ");
		}
			
	}
	if((r*tst)+(key-1)<=n&&n<=(r*tst)+((key-1)*2)){
		for(int i=1;i<=n-((r*tst)+(key-1));i++){
			pin();
		}
	}
		
	}
	
	else{if(n>=(tst-lk)){
		for(int i=1;i<=key;i++){
			pin();
		}
	}else if(n>=key&&n<(tst-lk)){
		for(int i=1;i<=(n-(key-1));i++){
			pin();
		}
	}else{
		for(int i=1;i<=n;i++){
			pin();
			printf("\n");
		}
		return 0;
		}
	}
		
	printf("\n");
	
	
	///////////////////////////////////////////////print n,l
	r==0?r++:0;
	if(key>2){
		l=n-((r*tst)-lk);
		if(l<0){
			r--;
			l=key-1-(n-(r*tst));
		}
		
		for(int i=1;i<=key-2;i++){
			int j=1;
			i<=l?0:j++;
			for(j;j<=(r*2)+1;j++){
				pin();
				for(int j=1;j<=tv;j++){
				printf(" ");
			}
			}
			printf("\n");
		}
	}
	/////////////////////////////////////////print last
	pin();
	if(n>=((r*tst)-(key-1))){
		for(int i=1;i<=n/(r*tst);i++){
			for(int j=1;j<=tv;j++){
				printf(" ");
			}
			for(int j=1;j<=key;j++){
				pin();
			}
		}
	}
	if(n>=((r*tst)-(key-1))&&n<(r*tst)){
		for(int j=1;j<=tv;j++){
				printf(" ");
			}
		for(int i=1;i<=(n-((r*tst)-(key-1)));i++){
			pin();
		}
	}
	
}
