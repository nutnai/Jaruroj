#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *Left = NULL;
    Node *Right = NULL;
};

Node *Create(int input)
{
    Node *newNode = new Node;
    newNode -> data = input;
    
    return newNode;
}

void Add(Node *Head,int input)
{  
    Node *chee = Head;
    Node *stop;
    while(chee != NULL)
    {
        stop = chee;
        if(input < chee -> data)
        {
            chee = chee -> Left;
        }
        else
        {
            chee = chee -> Right;
        }
    }
    
    if(input < stop -> data)
    {
        stop -> Left = Create(input);
    }
    else
    {
        stop -> Right = Create(input);
    }
}

void PrintAllNode(Node *Head)
{
    Node *chee = Head;
    cout<<chee -> data;
    if(chee -> Left != NULL)
    {
        PrintAllNode(chee -> Left);
    }
    if(chee -> Right != NULL)
    {
        PrintAllNode(chee -> Right);
    }

}
/*
void Search(Node *Head,int input)
{
    Node *chee = Head;
    while(chee != NULL)
    {
        stop = chee;
        cout<<chee -> data<<" ";
        if(chee -> data < input)
        {
            chee = chee -> Left;
        }
        else
        {
            chee = chee -> Right;
        }
    }

}*/

int main()
{
    Node *Head = NULL;
    int n;

    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        if(Head == NULL)
        {
            Head = Create(x);
        }
        else
        {
            Add(Head,x);
        }
    }
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int x;
        scanf("%d",&x);

    }
}