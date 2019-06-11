#ifndef HEADER_H
#define HEADER_H

#include <io.h> 
#include<string.h> 

typedef struct Node
{
	char* data;
	struct Node* child;
	struct Node* brother;
} Node;

char* MakeString(char*);
Node* Create(void *);
Node* AddBrother(Node*, void*);
Node* AddChild(Node *, void*);
void Print(Node*, int, FILE *, char*);
Node* Delete(Node*);
Node* Go(char*, Node*);


#endif 
