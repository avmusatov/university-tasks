#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#define M 3
#include "bits.h"

int inbit(Numbers k) {
	int bin = 0, p = 1;
	while (k.a) {
		bin = bin + ((k.a) % 2)*p;
		p *= 10;
		k.a /= 2;
	}
	return bin;
}

