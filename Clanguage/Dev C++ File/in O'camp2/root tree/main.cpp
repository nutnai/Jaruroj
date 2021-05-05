#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node*left,*right;
};

node *cn(int data){
    node *newn=new(node);
    newn->data=data;
    newn->left=NULL;
    newn->right=NULL;
    return newn;
}

void printpre(node *p){
    cout<<p->data<< " ";
    if(p->left!=NULL) printpre(p->left);
    if(p->right!=NULL) printpre(p->right);
}

void printin(node *p){
    if(p->left!=NULL) printin(p->left);
    cout<<p->data<< " ";
    if(p->right!=NULL) printin(p->right);
}

void printpost(node *p){
    if(p->left!=NULL) printpost(p->left);
    if(p->right!=NULL) printpost(p->right);
    cout<<p->data<< " ";
}

void printbf(node *root){
    node *p;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        p=q.front();
        q.pop();
        cout<<p->data<<" ";
        if(p->left!=NULL)q.push(p->left);
        if(p->right!=NULL)q.push(p->right);
    }
}

void insertt(node *p,int data){
    node *before;
    while(p!=NULL){
        before=p;
        if(p->data > data) p=p->left;
        else p=p->right;
    }
    if(before->data > data){
        before->left=cn(data);
    }else before->right=cn(data);
}

void printroottomini(node *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->left;
    }
}

void printroottomax(node *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->right;
    }
}

void printleaves(node *p){
    if(p->left!=NULL) printpre(p->left);
    if(p->right!=NULL) printpre(p->right);
    cout<<p->data<< " ";
}

int main(){
    node *root=NULL;

    int n,data;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>data;

        if(root==NULL){
        root=cn(data);
    }else insertt(root,data);
        }
        printpre(root);
        cout << "\n";
        printin(root);
        cout << "\n";
        printpost(root);
        cout << "\n";
        printroottomini(root);
        cout << "\n";
        printroottomax(root);
        cout << "\n";
        printleaves(root);

}
