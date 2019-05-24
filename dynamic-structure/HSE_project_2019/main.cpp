#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#define M 3
#define TASM 2

#include "bits.h"

#if TASM==1
int main()
{
	int a = 1, k;
	int mas[32];
	float b = 1;
	int n;
	while (a > 0 && b > 0) {
		printf("put numbers -> ");
		scanf_s("%d %f", &a, &b);
		if (a == 0 && b == 0) {
			break;
		}
		else {
			printf("%d ", a);
			for (int i = 0; i < 32; i++) {
				mas[i] = (a >> i) & 1;
			}
				for (int i = 31; i >= 0; i--)
					printf("%d", mas[i]);
				printf("\n");
			
		}
		getchar();
		getchar();
	}
	//int bin;
	//Numbers bit;
	//scanf("%d", &bit);
	//bin = inbit(bit);
	//printf("%d", bin);
	//getchar();

}
#elif TASM==2
int main()
{
	int n = 3;
	int s = 1;
	// char name[10];
	int name,col;
	int max = 0;
	int aliment;


	/*FILE *stream;
	stream = fopen("file.txt", "r");
	char msg[100];
	fseek(stream, 0, SEEK_SET);
	fscanf(stream, "%d", &n);*/
	Auto mas[10];
	
	mas[0].marka = YAZ;
	mas[0].color = white;
	mas[0].kolvo = 2;
	mas[0].cost = 400;
	mas[0].sklad = true;
	mas[0].sale = true;
	mas[1].marka = BMW;
	mas[1].color = blue;
	mas[1].kolvo = 2;
	mas[1].cost = 600;
	mas[1].sklad = true;
	mas[1].sale = true;
	mas[2].marka = Taiota;
	mas[2].color = red;
	mas[2].kolvo = 1;
	mas[2].cost = 700;
	mas[2].sklad = true;
	mas[2].sale = true;


	/*for (int i = 0; i < n; i++)
	{
		fscanf(stream, "%d %d %d %d %d %s", &mas[i].marka, &mas[i].color, &mas[i].kolvo, &mas[i].cost, &mas[i].sklad, &mas[i].sale);
	}
	fclose(stream);*/
	//scanf_s("%f", &name);
	char marks[][9] = {
"BMW",
"LADA",
"TAiota",
"YAZ",
"GAZ"
	};
	char colors[][9] = {
"white",
"bleak",
"red",
"blue"
	};
	for (int i = 0; i < n; i++) {
		scanf_s("%d %d", &name,&col);
		if (name==999)
		{
			_exit(0);
		}
		for (int j = 0; j < 3; j++) {
			if ((mas[j].marka == name)&&(mas[j].color==col)) {
				printf("%s %s ", marks[name], colors[col]);
				printf("%d  %d %i %i \n", mas[j].cost, mas[j].kolvo, mas[j].sklad, mas[j].sale);

			}	
		}

	}

	

	getchar();
	getchar();

}
#elif TASM==3
int main() {

}
#endif