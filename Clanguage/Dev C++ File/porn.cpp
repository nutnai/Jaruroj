#include <stdio.h>
#include <stdlib.h>
typedef struct nodeT
{
	int data;
	struct nodeT *next;
}nodeT;
nodeT *createNode (int data){
		nodeT *newNode = (nodeT *)malloc(sizeof(nodeT));
		if(newNode == NULL)
		return NULL;
		newNode->data = data;
		newNode->next = NULL;
		return newNode;
	}
int main(){
	
	
	
	
}
