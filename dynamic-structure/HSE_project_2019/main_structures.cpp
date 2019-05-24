#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "structures_header.h"

//int main(void) 
//{	
//	Train Trains[3];
//	Train mas[] = {
//		1,
//		12,
//		30,
//		15,
//		10,
//		"Nizhny",
//		2,
//		13,
//		40,
//		17,
//		30,
//		"Chkalovsk",
//		3,
//		13,
//		45,
//		18,
//		40,
//		"Kozino"
//	};
//	//Opening the file
//	int n = sizeof(Trains) / sizeof(Trains[0]);
//	FILE *f = fopen("Sample.txt", "wt");
//	FILE *inp = fopen("input.txt", "rt");
//	
//	//Reading from the file
//	if (f == NULL) {
//		perror("can not open the file");
//	}
//	else
//	{
//		for (int i = 0; i < 3; i++) {
//			fscanf(inp, "%d %d:%d %d:%d %s\n", &Trains[i].number, &Trains[i].arrival_time.hour,
//				&Trains[i].arrival_time.min, &Trains[i].departure_time.hour, &Trains[i].departure_time.min, &Trains[i].station_name);
//		}
//	}
//
//	// Writing to the file
//	if (f == NULL) {
//		perror("can not open the file");
//	}
//	else
//	{
//		for (int i = 0; i < n; i++)
//			fprintf(f, "%d %d:%d %d:%d %s\n", Trains[i].number, Trains[i].arrival_time.hour, 
//				Trains[i].arrival_time.min, Trains[i].departure_time.hour,Trains[i].departure_time.min, Trains[i].station_name);
//	}
//
//	fclose(f);
//}

