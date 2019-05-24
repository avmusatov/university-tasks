#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "structures_header.h"

int main(void) {
	TreeNode *root = NULL, *tmp = NULL;
	//tree: 10, 7, 9, 12, 6, 14, 3, 11, 4
	root = get_TreeNode(10);
	root = insert_in_tree(root, 7);
	root = insert_in_tree(root, 9);
	root = insert_in_tree(root, 12);
	root = insert_in_tree(root, 6);
	root = insert_in_tree(root, 14);
	root = insert_in_tree(root, 3);
	root = insert_in_tree(root, 11);
	root = insert_in_tree(root, 4);
	print_tree(root, 4);
	printf("__________________________________________________\n");
	printf("pre-order travers: ");
	preOrderTravers(root, print_TreeNode, NULL);
	printf("\nin-order travers: ");
	inOrderTravers(root, print_TreeNode, NULL);
	printf("\npost-order travers: ");
	postOrderTravers(root, print_TreeNode, NULL);

}