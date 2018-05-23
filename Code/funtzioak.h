#define _CRT_SECURE_NO_WARNINGS
#ifndef FUNTZIOAK_H
#define FUNTZIOAK_H

#define MAX_KAR 100

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
//noten soinuen helbidea
#define DO ".//sounds//Do_"
#define RE ".//sounds//Re_"
#define MI ".//sounds//Mi_"
#define FA ".//sounds//Fa_"
#define SOL ".//sounds//Sol_"
#define LA ".//sounds//La_"
#define SI ".//sounds//Si_"

//notak
#define Do 97
#define Re 115
#define Mi 100
#define Fa 102
#define Sol 103
#define La 104
#define Si 106
#define BUKATU 112


typedef struct Katea {

	int tecla;
	struct Katea* ptrHurrengoa;
}KATEA;

#endif
