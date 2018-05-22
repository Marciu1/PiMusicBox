#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#pragma comment(lib, "winmm.lib")
#include <windows.h>
#include "funtzioak.h"

char menua()
{
	char aukera;
	char str[100];

	printf("============================================\n\n\n\n");
	printf("                   MENUA                    ");
	printf("\n\n\n============================================\n");
	printf("a: Erreproduzitu.\n");
	printf("b:Grabatu.\n");
	printf("d: Grabatutakoa entzun.\n");
	
	printf("0: Irten\n");
	printf("===========================================\n");

	fgets(str, 100, stdin);
	sscanf(str, "%c", &aukera);

	return aukera;
}

void aukeraExekutatu(char aukera, KATEA ** burua)
{
	char str[100];
	switch (aukera) {
	case 'a':
		printf("\n TEKLAK\n");
		printf("a-->DO s-->RE d-->MI f-->FA g-->SOL h-->LA j-->SI\n");
		do {
			printf("Eman tekla bati: ");
			fgets(str, 100, stdin);
			erreproduzitu(str);
		} while (strcmp("0\n", str) != 0);
		break;
	case 'b':
		printf("\n TEKLAK\n");
		printf("a-->DO s-->RE d-->MI f-->FA g-->SOL h-->LA j-->SI\n");
		gorde(burua);
		break;
	case 'd':
		erreproduzituGordetakoa(*burua);
	default:
		printf("Sartu aukera egokia bat...\n");
		break;
	}
}

void erreproduzitu(char *str)
{

		switch (*str) {
		case 'a':

			PlaySound("A.wav", NULL, SND_ASYNC);
			break;
		case 's':
			PlaySound("B.wav", NULL, SND_ASYNC);
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
		case 'k':

			break;

		case '0':
			break;

		default:
			printf("Sartu aukera egokia bat...\n");
			break;

		}
	
}
void gorde(KATEA**burua) {
	char str[100];
	
	do {
		printf("Eman tekla bati(0 bukatzeko): ");
		fgets(str, 100, stdin);
		str[strlen(str) - 1] = '\0';
		erreproduzitu(str);
		erreserbatu(str, burua);

	} while (strcmp("0", str) != 0);


}
void erreserbatu(char *str, KATEA **BURUA) {
	KATEA *ptraux=*BURUA;
	
	if (*BURUA == NULL) {
		*BURUA = (KATEA*)malloc(sizeof(KATEA));
		strcpy((*BURUA)->tecla, str);
		(*BURUA)->ptrHurrengoa = NULL;
	}
	else {
		while (ptraux->ptrHurrengoa != NULL)ptraux = ptraux->ptrHurrengoa;
		ptraux->ptrHurrengoa = (KATEA*)malloc(sizeof(KATEA));
		strcpy(ptraux->ptrHurrengoa->tecla, str);
		ptraux->ptrHurrengoa->ptrHurrengoa = NULL;
	}
}
void erreproduzituGordetakoa(KATEA *burua) {

	while (burua != NULL) {
		Sleep(500);
		erreproduzitu(burua->tecla);
		burua = burua->ptrHurrengoa;
	}

}