#ifndef FUNTZIOAK_H
#define FUNTZIOAK_H

#define MAX_KAR 100;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct Katea {
	char tecla[MAX_KAR];
	struct Katea* ptrHurrengoa;
}KATEA;

void erreproduzitu(char *str);
void gorde(KATEA **burua);
void erreserbatu(char *str, KATEA **burua);
void erreproduzituGordetakoa(KATEA *burua);

#endif
