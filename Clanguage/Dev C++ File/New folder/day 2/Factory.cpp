 #include <bits/stdc++.h>
 using namespace std;

 int main()
 {
     int n,ans[3];
     scanf("%d",&n);
     int data[n+1];
     for(int i=1;i<=n;i++){
        scanf("%d",&data[i]);
     }
     ans[0]=2e9;
     for(int k=3;k<=n;k++){
        for(int j=2;j<k;j++){
            int a=0,b=0,c=0;
            for(int x=1;x<j;x++){
                a+=data[x];
            }
            for(int x=j;x<k;x++){
                b+=data[x];
            }
            for(int x=k;x<=n;x++){
                c+=data[x];
            }

            int m=max(max(a,b),c);
            int n=min(min(a,b),c);
            if(ans[0]>m-n){
                ans[0]=m-n;
                ans[1]=j;
                ans[2]=k;
            }
        }
     }
     cout<<ans[1]<<" "<<ans[2];
 }
