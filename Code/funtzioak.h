#define _CRT_SECURE_NO_WARNINGS

#ifndef FUNTZIOAK_H
#define FUNTZIOAK_H


#define MAX_KAR 100;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct Katea {

	char tecla[100];
	struct Katea* ptrHurrengoa;
}KATEA;

void erreproduzitu(char *str);
void gorde(KATEA ** burua);
void erreserbatu(char *str, KATEA **BURUA);
void erreproduzituGordetakoa(KATEA *burua);

#endif