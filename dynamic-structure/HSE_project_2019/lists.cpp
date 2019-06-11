#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


#include "structures_header.h"


//Functions for int-lists
void add2list(Node **pphead, int val)
{
	Node **pp = pphead, *pnew;
	while (*pp)
	{
		if (val < (*pp)->value)
			break;
		else
			pp = &((*pp)->pnext);
	}
	pnew = (Node*)malloc(sizeof(Node));
	pnew->value = val;
	pnew->pnext = *pp;
	*pp = pnew;
}


void print_list(Node *phead)
{
	Node* p = phead;
	while (p)
	{
		printf("%d ", p->value);
		p = p->pnext;
	}
	printf("\n");
}


void delete_list(Node *phead)
{
	if (phead)
	{
		delete_list(phead->pnext);
		if (phead)
			free(phead);
	}
}


Node* get_last_but_one(Node* phead) {
	if (phead == NULL) {
		exit(-2);
	}
	if (phead->pnext == NULL) {
		return NULL;
	}
	while (phead->pnext->pnext) {
		phead = phead->pnext;
	}
	return phead;
}

Node* get_last(Node* phead) {
	if (phead == NULL) {
		exit(-2);
	}
	if (phead->pnext == NULL) {
		return phead;
	}
	while (phead->pnext) {
		phead = phead->pnext;
	}
	return phead;
}


bool elems_are_same(Node *phead) {
	Node *p1 = phead,*p2 = phead;
	Node *plast = get_last(phead);
	int tmp1, tmp2;
	int flag = 0;
	while (p1 != plast) {
		tmp1 = p1->value;
		while (p2 != plast)
		{
			p2 = p2->pnext;
			tmp2 = p2->value;
			if (tmp1 == tmp2)
				flag = flag + 1;
			
		} 
		p1 = p1->pnext;
		p2 = p1;
	}
	if (flag > 0)
		return true;
	else
		return false;
}


Node *list1_xor_list2(Node *phead1, Node *phead2) 
{
	Node *p1 = phead1, *p2 = phead2;
	Node *phead3 = 0;
	Node *plast1 = get_last(phead1), *plast2 = get_last(phead2);
	int tmp1, tmp2;
	int flag;
	while (p1 != plast1) {
		tmp1 = p1->value;
		flag = 0;
		while (p2 != plast2)
		{
			tmp2 = p2->value;
			p2 = p2->pnext;
			if (tmp1 == tmp2)
				flag = 1;
		}
		if (flag == 0)
			add2list(&phead3, tmp1);
		p1 = p1->pnext;
		p2 = phead2;
	}

	//Procesing of the last element
	flag = 0;
	tmp1 = p1->value;
	while (p2) {
		tmp2 = p2->value;
		p2 = p2->pnext;
		if (tmp1 == tmp2)
			flag = 1;
	}
	if (flag == 0) {
		add2list(&phead3, tmp1);
	}

	return phead3;
}


//Functions for char-lists
void add2Charlist(CharNode **pphead, char val)
{
	CharNode *tmp = (CharNode*)malloc(sizeof(CharNode));
	tmp->value = val;
	tmp->pnext = (*pphead);
	(*pphead) = tmp;
}


void print_Charlist(CharNode *phead)
{
	CharNode* p = phead;
	while (p)
	{
		printf("%c ", p->value);
		p = p->pnext;
	}
	printf("\n");
}

void delete_Charlist(CharNode *phead)
{
	if (phead)
	{
		delete_list(phead->pnext);
		if (phead)
			free(phead);
	}
}

void div_list(CharNode *phead,Node **pphead1, CharNode **pphead2) 
{
	CharNode *p = phead;
	
	char tmp;
	while (p) {
		tmp = p->value;
		if (49<=(int)tmp && (int)tmp <= 57)
			add2list(&(*pphead1), (int)tmp - 48);
		else
			add2Charlist(&(*pphead2), tmp);
		p = p->pnext;
	}
}

//Functions for string-lists
void add2StringNode(char* s, StringNode ** pphead)
{
	StringNode* pnew = (StringNode*)malloc(sizeof(StringNode));
	pnew->str = (char*)malloc(strlen(s) + 1);
	strcpy(pnew->str, s);
	pnew->pnext = (*pphead);
	(*pphead) = pnew;
}


bool list1_in_list2(StringNode *phead1, StringNode *phead2)
{
	StringNode *p1 = phead1, *p2 = phead2;
	int flag;
	//char *tmp1, *tmp2;
	StringNode *tmp;
	while (p2 && p2->pnext) {
		flag = 0;
		tmp = p2;
		if (strcmp(p1->str,p2->str) == 0){
			while (p1 && p1->pnext) {
				p2 = p2->pnext;
				p1 = p1->pnext;
				if (strcmp(p1->str, p2->str) != 0)
					flag = 1;
			}
			if (flag == 0) {
				return true;
			}
			
		}
		p1 = phead1;
		p2 = tmp->pnext;
	}
	return false;
}

//Functions for stack
void push(CharNode **pphead, char value) {
	CharNode *tmp = malloc(sizeof(CharNode));
	if (tmp == NULL) {
		exit(-100);
	}
	tmp->pnext = *pphead;
	tmp->value = value;
	*pphead = tmp;
}


CharNode* pop(CharNode **pphead) {
	CharNode *out;
	if ((*pphead) == NULL) {
		exit(-100);
	}
	out = *pphead;
	*pphead = (*pphead)->pnext;
	return out;
}


bool IsEmpty(CharNode *phead)
{
	if (phead)
		return false;
	return true;
}


void printStack(const CharNode * phead) {
	printf("STACK: ");
	while (phead) {
		printf("%c", phead->value);
		phead = phead->pnext;
	}
}


char peek(const CharNode* phead) {
	if (phead == NULL) {
		exit(-100);
	}
	return phead->value;
}


bool IsPalindrom(char *s, int size) 
{
	CharNode *phead = NULL;
	CharNode *tmp_phead = NULL;
	bool flag = true;
	int j;

	for (int i = 0; i < size / 2; i++) {
		push(&phead, s[i]);
	}

	if (size % 2 == 0)
		j = size / 2;
	else
		j = size / 2 + 1;

	while (phead) {
		tmp_phead = pop(&phead);
		if ((int)s[j] != (int)(tmp_phead->value))
			flag = false;
		free(tmp_phead);
		j++;
	}
	return flag;
}


bool brackets_are_right(char *s, int len)
{
	CharNode *phead = NULL, *tmp_phead = NULL;
	char tmp, right = ')', left = '(';
	for (int i = 0; i < len; i++)
	{
		if (s[i] == left || s[i] == right) {
			if (IsEmpty(phead))
				push(&phead, s[i]);
			else
			{
				tmp = peek(phead);
				if (tmp == left && s[i] == right) {
					tmp_phead = pop(&phead);
					free(tmp_phead);
				}
				else
					push(&phead, s[i]);
			}
		}
	}
	if (IsEmpty(phead))
		return true;
	else
		return false;
}

//Functions for BST
TreeNode *get_TreeNode(T value)
{
	TreeNode *tmp = (TreeNode*)malloc(sizeof(TreeNode));
	tmp->data = value;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

TreeNode *insert_in_tree(TreeNode *root, T value)
{
	if (root == NULL)
		return get_TreeNode(value);
	else if (root->data < value) {
		root->right = insert_in_tree(root->right, value);
		return root;
	}
	else if (root->data > value) {
		root->left = insert_in_tree(root->left, value);
		return root;
	}
	else
		exit(3);
				
}


TreeNode *find_in_tree(TreeNode *root, T value) 
{
	if (root == NULL) {
		printf("Tree is empty! \n");
		exit(4);
	}
	if (root->data > value) {
		return find_in_tree(root->left, value);
	}
	else if (root->data < value) {
		return find_in_tree(root->right, value);
	}
	else {
		return root;
	}
}


TreeNode *find_min_TreeNode(TreeNode *root)
{
	if (root == NULL) {
		printf("Tree is empty! \n");
		exit(4);
	}
	if (root->left)
		return find_min_TreeNode(root->left);
	return root;
}


TreeNode *find_max_TreeNode(TreeNode *root)
{
	if (root == NULL) {
		printf("Tree is empty! \n");
		exit(4);
	}
	if (root->right)
		return find_max_TreeNode(root->right);
	return root;
}


TreeNode *delete_TreeNode(TreeNode *root, T value) 
{
	if (root == NULL) {
		printf("No such elements! \n");
		return NULL;
	}
	else if (root->data > value) {
		root->left = delete_TreeNode(root->left, value);
		return root;
	}
	else if (root->data < value) {
		root->right = delete_TreeNode(root->right, value);
		return root;
	}
	else {
		if (root->left && root->right) {
			TreeNode* locMax = find_max_TreeNode(root->left);
			root->data = locMax->data;
			root->left = delete_TreeNode(root->left, locMax->data);
			return root;
		}
		else if (root->left) {
			TreeNode *tmp = root->left;
			free(root);
			return tmp;
		}
		else if (root->right) {
			TreeNode *tmp = root->right;
			free(root);
			return tmp;
		}
		else {
			free(root);
			return NULL;
		}
		
	}
}


void print_tree(TreeNode* root, int level)
{
	if (root)
		print_tree(root->right, level + 1);
	for (int i = 0; i < level; i++)
		printf("   ");
	if (root)
		printf("%d  \n", root->data);
	else
		printf("#\n");
	if (root)
		print_tree(root->left, level + 1);
}


void preOrderTravers(TreeNode* root, void(*visit)(TreeNode*, void*), void *params) {
	if (root) {
		visit(root, params);
		preOrderTravers(root->left, visit, params);
		preOrderTravers(root->right, visit, params);
	}
}


void inOrderTravers(TreeNode* root, void(*visit)(TreeNode*, void*), void *params) {
	if (root) {
		inOrderTravers(root->left, visit, params);
		visit(root, params);
		inOrderTravers(root->right, visit, params);
	}
}


void postOrderTravers(TreeNode* root, void(*visit)(TreeNode*, void*), void *params) {
	if (root) {
		postOrderTravers(root->left, visit, params);
		postOrderTravers(root->right, visit, params);
		visit(root, params);
	}
}

void print_TreeNode(TreeNode *current, void *args) {
	printf("%d ", current->data);
}

//Convert infix to postfix expression
void infix_to_postfix(char *s, int len)
{
	CharNode *opStack = NULL;
	CharNode *resStack = NULL;
	char tmp,topElem, tmpStr[128],tmpElem;

	for (int i = 0; i < len; i++) {
		tmp = s[i];
		if ((int)'1' <= (int)tmp && (int)tmp <= (int)'9') {
			push(&resStack, tmp);
		}
		else if ((int)tmp == (int)'(') {
			push(&opStack, tmp);
		}
		else if ((int)tmp == (int)')') {
			topElem = pop(&opStack)->value;
			while ((int)topElem != (int)'(') {
				push(&resStack, topElem);
				topElem = pop(&opStack)->value;
			}
		}
		else {
			while (IsEmpty(opStack) == false && precedence(tmp) <= precedence(peek(opStack))) {
				tmpElem = pop(&opStack)->value;
				push(&resStack, tmpElem);
			}
			push(&opStack, tmp);
		}
	}
	printStack(resStack);
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
