#include <bits/stdc++.h>
using namespace std;
struct tree {
    int value;
    tree *chee,*por;
} t;

bool check;
tree *god=NULL;

tree *create(int ka) {
    tree *newtree=new(tree);
    newtree->por=NULL;
    newtree->value=ka;
    newtree->chee=NULL;
    return newtree;
}

void add(tree *root,int ka) {
    while(root->chee!=NULL)
        root=root->chee;
    root->chee=create(ka);
    root->chee->por=root;
}

void printtest(tree *root) {
    cout<<root->value<<" ";
    if(root->chee!=NULL)
        printtest(root->chee);
}

int pluss(int x,int y) {
    int a[]= {2,1,0};
    int b[]= {2,1,1};
    int c[]= {1,2,1};
    if(x==0)
        return a[y];
    if(x==1)
        return b[y];
    return c[y];
}

void kit(tree *rootcp) {
    tree *root=rootcp;
    if(check)
        return;
    if(root->por==NULL && root->chee==NULL){
        if(root->value==0){
            check=true;
        }
        return;
    }
    ///+
    if(root->chee!=NULL) {
        tree *neww=create(pluss(root->value,root->chee->value));
        if(root->por!=NULL){
             root->por->chee=neww;
             neww->por=root->por;
        }

        else {
                neww->por=NULL;
                god=neww;
        }
        neww->chee=root->chee->chee;
        kit(god);
    }
    ///skip
    root=rootcp;
    if(root->chee->chee!=NULL){
        kit(root->chee);
    }
}


int main() {
    //for(int t=1;t<=20;t++){
    int n;
    check=false;
    scanf("%d",&n);
    int ka[n+1];
    char c;
    scanf("%c",&c);
    for(int i=1; i<=n; i++) {
        scanf("%c",&c);
        int x=c-'0';
        if(god==NULL)
            god=create(x);
        else
            add(god,x);
    }
    kit(god);
    if(check)
        cout<<"yes\n";
    else cout<<"no\n";
    //}
}
