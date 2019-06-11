#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


#include "header.h"

int main() {
	Node *pStack = NULL;
	char s[] = "(1+(3*3+2))" , postfix[128];
	int len = strlen(s);
	strcpy(postfix,infixToPostfix(s, len));
	printf("String to postfix: \'%s\' \n", postfix);
	len = strlen(postfix);
	printf("Math = %d", postfixMath(postfix,len));

	
}