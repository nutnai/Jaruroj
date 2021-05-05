#include <stdio.h>

main(){
	float me,sum=0;
	int n;
	scanf("%d",&n);
	int a[n],b[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		sum=sum+a[i];
		b[i]=0;
	}
	
	for(int i=0;i<n;i++){
		int j=0;
		for(j;j<n-1;j++){
			if(a[j]>a[j+1]){
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	
	if(n%2==0){
		me=(a[(n/2)-1]+a[(n/2)])/2.0;
	}else(
	me=a[((n+1)/2)-1]);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i]==a[j]){
			b[i]++;
			}
		}
	}
	int max=b[0],m=0;
	for(int i=1;i<n;i++){
		if(max<=b[i]){
			max=b[i];
			m=i;
		}
	}
	
	printf("%0.1f\n%0.1f\n%0.1f",sum/n,me,(float)a[m]);
}
