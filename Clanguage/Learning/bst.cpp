#include <bits/stdc++.h>
using namespace std;

struct tree{
    int data;
    tree* l;
    tree* r;
};

tree newnode(int data){
    tree *node = new tree; 
    node->data=data;
    node->l=NULL;
    node->r=NULL;
    return(*node);
}

tree insert(tree* root,int data){
    if(data >= root->data){
        *root->r=newnode(data);
    }else
    {
        *root->l=newnode(data);
    }
    return;
}

void print(tree* root){
    
    if(root->l!=NULL)print(root->l);
    cout<<root->data<<" ";
    if(root->r!=NULL)print(root->r);
    
}

int main(){
    tree *root;
    root = NULL;
    
    while(true){
        char c;
        scanf("%c",&c);
        int data;
        scanf("%d",&data);
        if(c=='a'){
            if(root==NULL){
                insert(root,data);
            }else{
            tree* chee=root;
            while(chee=NULL){
                if(data >= chee->data){
                    chee=chee->r;
                }else
                {
                    chee=chee->l;
                }
                
            }
            insert(chee,data);
        }
        }else if(c=='p'){
            if(root!=NULL){
                print(root); 
            }else{
                cout<<"none";
            }
            
        }
        
    }

    
}