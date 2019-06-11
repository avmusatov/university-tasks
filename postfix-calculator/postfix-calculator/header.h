#ifndef HEADER_H
#define HEADER_H
	
typedef struct Node
{
	int value;
	struct Node *pnext;
}Node;

void appendToList(Node*, int);
void pushToStack(Node**, int);
void printList(Node*);
void printStack(Node*);
Node* getLast(Node *head);
char * infixToPostfix(char *s, int len);
int postfixMath(char *expresion, int len);
int precedence(char tmp);
char peek(const Node* phead);
int doMath(int a, int b, char operation);

#endif