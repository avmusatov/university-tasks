#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "structures_header.h"


//int main()
//{
//	Node *phead= 0;
//	add2list(&phead, 1);
//	add2list(&phead, 2);
//	add2list(&phead, 5);
//	add2list(&phead, 4);
//	add2list(&phead, 5);
//	add2list(&phead, 5);
//	if (elems_are_same(phead))
//		printf("True\n");
//	else
//		printf("False\n");
//
//	printf("Elements of the list:\n");
//	print_list(phead);
//	delete_list(phead);
//}


//int main(void)
//{
//	Node *phead1 = 0, *phead2 = 0, *phead3 = 0;
//
//	add2list(&phead1, 1);
//	add2list(&phead1, 2);
//	add2list(&phead1, 3);
//	add2list(&phead1, 4);
//	add2list(&phead1, 5);
//	add2list(&phead1, 6);
//	
//	add2list(&phead2, 15);
//	add2list(&phead2, 10);
//	add2list(&phead2, 2);
//	add2list(&phead2, 11);
//	add2list(&phead2, 6);
//	add2list(&phead2, 12);
//
//	phead3 = list1_xor_list2(phead1, phead2);
//	printf("Elements of the list1:\n");
//	print_list(phead1);
//	printf("\n");
//	printf("Elements of the list2:\n");
//	print_list(phead2);
//	printf("\n");
//	printf("Elements of the list3:\n");
//	print_list(phead3);
//
//	delete_list(phead1);
//	delete_list(phead2);
//	delete_list(phead3);
//}


//int main()
//{
//	CharNode *phead = 0;
//	add2Charlist(&phead, '1');
//	add2Charlist(&phead, '2');
//	add2Charlist(&phead, 'g');
//	add2Charlist(&phead, '4');
//	add2Charlist(&phead, 'h');
//	add2Charlist(&phead, '6');
//
//	Node *phead1 = 0;
//	CharNode *phead2 = 0;
//	div_list(phead, &phead1, &phead2);
//	printf("Elements of the original list:\n");
//	print_Charlist(phead);
//	printf("Elements of the list with numbers:\n");
//	print_list(phead1);
//	printf("Elements of the list with symbols:\n");
//	print_Charlist(phead2);
//}

//int main(void) {
//	StringNode *list1 = NULL, *list2 = NULL;
//
//	add2StringNode("d", &list1);
//	add2StringNode("d", &list1);
//	add2StringNode("fh", &list2);
//	add2StringNode("dr", &list2);
//	add2StringNode("d", &list2);
//	add2StringNode("d", &list2);
//	add2StringNode("d", &list2);
//	add2StringNode("d", &list2);
//	add2StringNode("d", &list2);
//	add2StringNode("d", &list2);
//
//	if (list1_in_list2(list1,list2))
//		printf("True\n");
//	else
//		printf("False\n");
//}