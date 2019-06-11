#ifndef HEADER_H
#define HEADER_H

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
TreeNode *deleteTreeNode(TreeNode *root, T value);
TreeNode *find_in_tree(TreeNode *root, T value);
void printTree(TreeNode* root, int level);
void preOrderTravers(TreeNode* root, void(*visit)(TreeNode*, void*), void *params);
void inOrderTravers(TreeNode* root, void(*visit)(TreeNode*, void*), void *params);
void postOrderTravers(TreeNode* root, void(*visit)(TreeNode*, void*), void *params);
void printTreeNode(TreeNode *current, void *args);
void findMaxFullTree(TreeNode *root, void *args);

#endif