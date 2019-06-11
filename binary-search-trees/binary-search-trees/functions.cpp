#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


#include "header.h"

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


TreeNode *deleteTreeNode(TreeNode *root, T value)
{
	if (root == NULL) {
		printf("No such elements! \n");
		return NULL;
	}
	else if (root->data > value) {
		root->left = deleteTreeNode(root->left, value);
		return root;
	}
	else if (root->data < value) {
		root->right = deleteTreeNode(root->right, value);
		return root;
	}
	else {
		if (root->left && root->right) {
			TreeNode* locMax = find_max_TreeNode(root->left);
			root->data = locMax->data;
			root->left = deleteTreeNode(root->left, locMax->data);
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


void printTree(TreeNode* root, int level)
{
	if (root) printTree(root->right, level + 1);
	for (int i = 0; i < level; i++) printf("   ");
	if (root) printf("%d  \n", root->data);
	else printf("#\n");
	if (root) printTree(root->left, level + 1);
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

void printTreeNode(TreeNode *current, void *args) {
	printf("%d ", current->data);
}

void findMaxFullTree(TreeNode *root, void *args) {
	if (root->left && !(root->right)) {
		deleteTreeNode(root, root->left->data);
	}
	else if (root->right && !(root->left)) {
		deleteTreeNode(root, root->right->data);
	}
}

void findMaxLine(TreeNode *root) {
	static int counter = 0, maxCounter = 0;

	if (root->left) findMaxLine(root->left);
	else if (!(root->left) && !(root->right)) {
		if (counter > maxCounter) {
			maxCounter = counter;
			counter = 0;
		}
	}
}