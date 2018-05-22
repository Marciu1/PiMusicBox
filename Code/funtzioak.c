#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "funtzioak.h"

char menua()
{
	char aukera;
	char str[MAX_KAR];

	printf("============================================\n\n\n\n");
	printf("                   MENUA                    ");
	printf("\n\n\n============================================\n");
	printf("a: Erreproduzitu.\n");
	printf("b:Grabatu.\n");
	printf("d: Grabatutakoa entzun.\n");
	
	printf("0: Irten\n");
	printf("===========================================\n");

	fgets(str, MAX_KAR, stdin);
	sscanf(str, "%c", &aukera);

	return aukera;
}

void aukeraExekutatu(char aukera, KATEA ** burua)
{
	switch (aukera) {
	case 'a':
		
		break;
	case 'b':
		
		break;
	case 'd':
		
	default:
		printf("Sartu aukera egokia bat...\n");
		break;
	}
}

void erreproduzitu()
{
	char nota,str[100];


	printf("Jo hurrengo tekla:");
	fgets(str, 100, stdin);
	sscanf(str, "%c", &nota);

	switch (nota) {
	case 'a':

		break;
	case 's':

		break;
	case 'd':

		break;
	case 'f':

		break;
	case 'g':

		break;
	case 'h':

		break;
	case 'j':

		break;


	default:
		printf("Sartu aukera egokia bat...\n");
		break;
	}

}

void grabatu() 
{

}
