#include <bits/stdc++.h>
using namespace std;

vector<int> ans,path;

struct tree {
    int data;
    tree *left,*right;
} t;

tree *add(int in) {
    tree *newn=new(tree);
    newn->data=in;
    newn->left=NULL;
    newn->right=NULL;
    return newn;
}

void insertt(tree *root,int in) {
    tree *chee;
    while(root!=NULL) {
        chee=root;
        if(root->data>in)
            root=root->left;
        else
            root=root->right;

    }
    if(chee->data>in)
        chee->left=add(in);
    else
        chee->right=add(in);

}

void printtest(tree *root){
    cout<<root->data<<" ";
    if(root->right!=NULL)
        printtest(root->right);
    if(root->left!=NULL)
        printtest(root->left);
}

void sert(tree *root,int wantknow) {
    if(root->data==wantknow) {
        ans=path;
        if(root->right!=NULL) {
            path.push_back(root->right->data);
            sert(root->right,wantknow);
        }
    } else {
        if(root->right!=NULL) {
            path.push_back(root->right->data);
            sert(root->right,wantknow);
            path.pop_back();
        }
        if(root->left!=NULL) {
            path.push_back(root->left->data);
            sert(root->left,wantknow);
            path.pop_back();
        }

    }
}

void sertbabmaimee(tree *root,int wantknow){
    while(root!=NULL) {
            ans.push_back(root->data);
        if(root->data>wantknow)
            root=root->left;
        else
            root=root->right;

    }
    ans.push_back(0);
}

int main() {
    tree *root=NULL;
    int n;

    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        int in;
        scanf("%d",&in);
        if(root!=NULL) {
            insertt(root,in);
        } else
            root=add(in);
    }
    int kumtam,wantknow;
    scanf("%d",&kumtam);
    for(int i=0; i<kumtam; i++) {
        scanf("%d",&wantknow);
        path.push_back(root->data);
        sert(root,wantknow);

        if(ans.empty()){
            sertbabmaimee(root,wantknow);
        }

        for(auto i:ans) {
            cout<<i<<" ";
        }
        ans.clear();
        path.clear();
        cout<<"\n";
    }
}
