#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    for(int nt=1; nt<=t; nt++) {
        list<char> l;
        string s;
        cin>>s;
        list<char>::iterator po;
        po=l.begin();
        int rob=s.size();
        int before=0;
        int kitt=0;
        for(int i=0; i<rob; i++) {
            int x=s[i]-'0';
            int kit=before-x;
            if(x==0) {
                for(int ll=0; ll<kit; ll++)
                    l.insert(po,')');
                l.insert(po,x+'0');
                before=0;
                kitt=0;
                continue;
            }
            if(kit<0) {
                for(int ll=kit; ll<0; ll++)
                    l.insert(po,'(');
                l.insert(po,x+'0');
            } else if(kit>0) {
                for(int ll=0; ll<kit; ll++)
                    l.insert(po,')');
                l.insert(po,x+'0');
            }
            if(kit==0)
                l.insert(po,x+'0');

            kitt=x;
            before=x;
        }
        for(int i=1; i<=kitt; i++)
            l.insert(po,')');

        cout<<"Case #"<<nt<<": ";
        for(auto x:l)
            cout<<x;
        cout<<"\n";
    }

}
