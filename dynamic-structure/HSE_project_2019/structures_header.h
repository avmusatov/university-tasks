#ifndef STRUCTURES_HEADER_H
#define STRUCTURES_HEADER_H

typedef struct Time {
	int hour;
	int min;
}Time;


typedef struct Train
{
	int number;
	Time arrival_time;
	Time departure_time;
	char station_name[128];
}Train;


typedef struct Node {
	int value;
	struct Node *pnext;
}Node;


void add2list(Node **pphead, int val);
void print_list(Node *phead);
void delete_list(Node *phead);
bool elems_are_same(Node *phead);
Node* get_last_but_one(Node* phead);
Node* get_last(Node* phead);
Node *list1_xor_list2(Node *phead1, Node *phead2);


typedef struct CharNode {
	char value;
	struct CharNode *pnext;
}CharNode;

void add2Charlist(CharNode **pphead, char val);
void print_Charlist(CharNode *phead);
void delete_Charlist(CharNode *phead);
void div_list(CharNode *phead, Node **pphead1, CharNode **pphead2);


typedef struct StringNode {
	char *str;
	struct StringNode *pnext;
}StringNode;

void add2StringNode(char* s, StringNode ** pphead);
bool list1_in_list2(StringNode *phead1, StringNode *phead2);

//stack
void push(CharNode **pphead, char value);
CharNode* pop(CharNode **pphead);
void printStack(const CharNode * phead);
char peek(const CharNode* phead);
bool IsEmpty(CharNode *phead);
bool IsPalindrom(char *s, int size);
bool brackets_are_right(char *s, int len);

//binary search tree
typedef int T;

typedef struct TreeNode {
	T data;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;

TreeNode *get_TreeNode(T value);
TreeNode *insert_in_tree(TreeNode *root, T value);
TreeNode *find_min_TreeNode(TreeNode *root);
TreeNode *find_max_TreeNode(TreeNode *root);
TreeNode *delete_TreeNode(TreeNode *root, T value);
TreeNode *find_in_tree(TreeNode *root, T value);
void print_tree(TreeNode* root, int level);
void preOrderTravers(TreeNode* root, void(*visit)(TreeNode*, void*), void *params);
void inOrderTravers(TreeNode* root, void(*visit)(TreeNode*, void*), void *params);
void postOrderTravers(TreeNode* root, void(*visit)(TreeNode*, void*), void *params);
void print_TreeNode(TreeNode *current, void *args);

int precedence(char tmp);
void infix_to_postfix(char *s, int len);

#endif