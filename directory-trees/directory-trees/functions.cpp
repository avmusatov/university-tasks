#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <io.h>
#include <time.h>

#include "header.h"

char* MakeString(char* str)
{
	char * temp = (char*)malloc(strlen(str) + 1);
	strcpy(temp, str);
	return temp;
}


Node* Create(void *_data)
{
	Node* root = (Node*)malloc(sizeof(Node));
	root->data = (char*)_data;
	root->brother = NULL;
	root->child = NULL;
	return root;
}


Node* AddBrother(Node* oldbrother, void* _data)
{
	Node* p = oldbrother;
	while (p&& p->brother)
		p = p->brother;
	Node* temp;
	temp = (Node*)malloc(sizeof(Node));
	temp->data = (char*)_data;
	temp->brother = NULL;
	temp->child = NULL;
	if (p)
		p->brother = temp;
	else
		p = temp;
	return oldbrother;
}


Node* AddChild(Node * par, void* _data)
{
	if (par->child)
		par->child = AddBrother(par->child, _data);
	else
	{
		par->child = (Node*)malloc(sizeof(Node));
		par->child->data = (char*)_data;
		par->child->child = NULL;
		par->child->brother = NULL;
	}
	return par;
}
int IsFileCorrect(char *str, char* str2) {
	int l1, l2;
	char a, b;
	l1 = strlen(str);
	l2 = strlen(str2);
	for (int i = l2 - 1; i >= 0; i--) {
		a = *(str2 + i);
		b = *(str + l1 + i - l2);
		if (a != b) return 0;
	}
	return 1;
}
void Print(Node* root, int level, FILE *fout, char* str2)
{
	Node* p = root;
	if (IsFileCorrect(p->data, str2) == 1) fprintf(fout, "%s\n", p->data);
	if (p->child)
		Print(p->child, level + 1, fout, str2);
	if (p->brother)
		Print(p->brother, level, fout, str2);
}


Node* Delete(Node* root)
{
	Node* p = root;
	if (p->brother)
		p->brother = Delete(p->brother);
	if (p->child)
		p->child = Delete(p->child);
	free(p);
	return 0;
}


Node* Go(char* path, Node* root)
{
	struct _finddata_t fc;
	intptr_t hFile = _findfirst(path, &fc);
	if (hFile == -1)
		return root;
	_findnext(hFile, &fc);
	while (_findnext(hFile, &fc) == 0)
	{
		char* temp = MakeString(fc.name);
		if (fc.attrib & _A_SUBDIR)
		{

			root = AddChild(root, (void*)temp);
			char path1[1000];
			strcpy(path1, path);
			strcpy(path1 + strlen(path1) - 3, fc.name);
			strcat(path1, "\\*.*");

			Node* p = root->child;
			while (p->brother)
				p = p->brother;
			p = Go(path1, p);
		}
		else
			root = AddChild(root, (void*)temp);
	}
	return root;
}