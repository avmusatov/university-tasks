#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "structures_header.h"

//int main(void) {
//	CharNode *phead = NULL;
//	CharNode *tmp_phead = NULL;
//	int size;
//	printf("Input size of string: ");
//	scanf("%d", &size);
//	char *s = (char*)malloc(sizeof(char) * size + 2);
//	scanf("%s", s);
//	for (int i = 0; i < size; i++) {
//		push(&phead, s[i]);
//	}
//	printStack(phead);
//	while (phead) {
//		tmp_phead = pop(&phead);
//		free(tmp_phead);
//	}
//	free(s);
//}


//int main(void) {
//	CharNode *phead = NULL;
//	CharNode *tmp_phead = NULL;
//	int size;
//	printf("Input size of string: ");
//	scanf("%d", &size);
//	char *s = (char*)malloc(sizeof(char) * size + 2);
//	printf("Input string: ");
//	scanf("%s", s);
//	
//	if (IsPalindrom(s,size))
//		printf("Palindrom\n");
//	else
//		printf("No palindrom\n");
//	free(s);
//}


//int main(void) {
//	FILE * f_in = fopen("stack_in.txt", "rt");
//	FILE * f_out = fopen("stack_out.txt", "wt");
//	char buffer[128];
//	CharNode *phead = NULL, *tmp_phead = NULL;
//	int len,endf;
//
//	if (f_in == NULL) {
//		printf("Error opening file\n");
//		exit(-3);
//	}
//
//	if (f_out == NULL) {
//		printf("Error opening file\n");
//		exit(-3);
//	}
//
//	do {
//		fgets(buffer, 127, f_in);
//		len = strlen(buffer);
//		for (int i = 0; i < len; i++)
//			push(&phead, buffer[i]);
//		for (int i = 0; i < len; i++) {
//			tmp_phead = pop(&phead);
//			fputc(tmp_phead->value, f_out);
//			free(tmp_phead);
//		}
//		endf = fgetc(f_in);
//	} while (endf != EOF);
//
//	fclose(f_in);
//	fclose(f_out);
//}

//
//int main(void) {
//	int len;
//	char s[128];
//	printf("Input string: ");
//	gets(s);
//	len = strlen(s);
//	if (brackets_are_right(s, len))
//		printf("Right\n");
//	else
//		printf("Wrong\n");
//}