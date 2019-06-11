#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


#include "header.h"


void pushToStack(Node **pphead, int value) {
	Node *tmp = (Node*)malloc(sizeof(Node));
	tmp->value = value;
	tmp->pnext = (*pphead);
	(*pphead) = tmp;
}


void printStack(Node *phead) {
	Node* p = phead;
	printf("Stack: \n");
	while (p)
	{
		printf("%c ", p->value);
		p = p->pnext;
	}
	printf("\n");
}

Node* popFromStack(Node **pphead) {
	Node *out;
	if ((*pphead) == NULL) {
		exit(-100);
	}
	out = *pphead;
	*pphead = (*pphead)->pnext;
	return out;
}

bool IsEmpty(Node *phead)
{
	if (phead)
		return false;
	return true;
}


char peek(const Node* phead) {
	if (phead == NULL) {
		exit(-100);
	}
	return phead->value;
}

char * infixToPostfix(char *s, int len)
{
	Node *opStack = NULL;
	char resStr[128];
	int tmp, topElem,tmpElem;
	int j = 0;

	for (int i = 0; i < len; i++) {
		tmp = (int)(s[i]);
		if ((int)'1' <= tmp && tmp <= (int)'9') {
			resStr[j++] = (char)tmp;
		}
		else if (tmp == (int)'(') {
			pushToStack(&opStack, tmp);
		}
		else if (tmp == (int)')') {
			topElem = popFromStack(&opStack)->value;
			while (topElem != (int)'(') {
				resStr[j++] = (char)topElem;
				topElem = popFromStack(&opStack)->value;
			}
		}
		else {
			while (IsEmpty(opStack) == false && precedence(tmp) <= precedence(peek(opStack))) {
				tmpElem = popFromStack(&opStack)->value;
				resStr[j++] = (char)tmpElem;
			}
			pushToStack(&opStack, tmp);
		}
	}
	resStr[j] = '\0';
	return resStr;
}

int postfixMath(char *expresion, int len) {
	Node *operandStack = NULL;
	int operand1 , operand2;
	int token;
	int i = 0;

	for (i = 0; i < len; i++) {
		token = (int)(expresion[i]);
		if ((int)'1' <= token && token <= (int)'9') {
			token = token - (int)'1' + 1;
			pushToStack(&operandStack, token);
		}
		else {
			operand2 = popFromStack(&operandStack)->value;
			operand1 = popFromStack(&operandStack)->value;
			pushToStack(&operandStack, doMath(operand1, operand2, token));
		}
	}
	return popFromStack(&operandStack)->value;
}

int precedence(char tmp) {
	switch (tmp) {
	case '*':
		return 3;
	case '/':
		return 3;
	case '+':
		return 2;
	case '-':
		return 2;
	default:
		return 1;
	}
}

int doMath(int a, int b, char operation) {
	switch (operation) {
	case '*':
		return a * b;
	case '+':
		return a + b;
	case '-':
		return a - b;
	}
}