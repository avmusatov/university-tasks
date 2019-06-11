#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <io.h>
#include <conio.h>

#include "header.h"


int main(int argc, char* argv[]) {
	argc--;
	int i = 1;
	FILE * pf;
	Node* pTree = NULL;
	char str[50], rash[50];
	while (argc > 0) {
		pTree = Create(argv[i]);
		i++;
		argc--;
		pf = fopen(argv[i], "w");
		if (pf == NULL) {
			printf("File does not create: %s\n", argv[i]);
			system("pause");
			return 0;
		}
		i++;
		argc--;
		strcpy(str, argv[i - 2]);
		strcat(str, "\\*.*");
		strcpy(rash, argv[i]);

		i++;
		argc--;

		Go(str, pTree);

		Print(pTree, 3, pf, rash);

		pTree = Delete(pTree);
		fclose(pf);
	}
	return 0;
}
