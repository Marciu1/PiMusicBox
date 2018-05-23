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

	printf("============================================\n");
	printf("|                   MENUA                    ");
	printf("\n============================================\n");
	printf("| a: Erreproduzitu.\n");
	printf("| b: Grabatu.\n");
	printf("| d: Grabatutakoa entzun.\n");
	printf("| 0: Irten\n");
	printf("===========================================\n");

	fgets(str, MAX_KAR, stdin);
	sscanf(str, "%c", &aukera);

	return aukera;
}
int instrumento()
{
	int instrumentua = 0;
	char str[128];

	do {
		printf("============================================\n\n\n\n");
		printf("                 AUKERAK                    ");
		printf("\n\n\n============================================\n");
		printf("1: PIANO\n");
		printf("2: 8-BIT\n");
		printf("3: TROMPETA\n");
		printf("4: EXTRAS\n");		
		printf("===========================================\n");

		fgets(str, 128, stdin);
		sscanf(str, "%d", &instrumentua);
	} while ((instrumentua > 0) || (instrumentua < 5));

	return instrumentua;
}

<<<<<<< HEAD

void aukeraExekutatu(char aukera, KATEA ** burua,int instrumentua)
{
	switch (aukera) {
	case 'a':
		printf("\n TEKLAK\n");
		printf("a-->DO s-->RE d-->MI f-->FA g-->SOL h-->LA j-->SI//gelditzeko 0 sakatu");
		moduLibrea(instrumentua);

		
		break;
	case 'b':
		printf("\n TEKLAK\n");
		printf("a-->DO s-->RE d-->MI f-->FA g-->SOL h-->LA j-->SI//grabaketa bukatzeko 'p' sakatu");
		zerrendaBete(instrumentua, burua);
		
		break;
	case 'd':
		
=======
void aukeraExekutatu(char aukera, KATEA **burua)
{
	char str[100];
	switch (aukera)
	{
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
		break;
>>>>>>> master
	default:
		printf("Sartu aukera egokia bat...\n");
		break;
	}
}
////////////////////////
void moduLibrea(int instrumentua)
{
<<<<<<< HEAD
	char tecla='1';

	while (tecla != 0)
	{
		tecla =notaEskatu() ;
		erreproduzitu(instrumentua,tecla);
	}
}
int notaEskatu()
{
	char str[100];
	int nota;
=======
		switch (*str)
		{
		case 'a':

			PlaySound("A.wav", NULL, SND_ASYNC);
			break;
		case 's':
			PlaySound("B.wav", NULL, SND_ASYNC);
			break;
		case 'd':

			break;
		case 'f':
>>>>>>> master

	printf("Jo hurrengo tekla:");
	fgets(str, 100, stdin);
	sscanf(str, "%d", &nota);

	return nota;
}
int erreproduzitu(int instrumentua,int nota)
{

	switch (nota) {
		char soinua[100];
	case '97'/*a*/:
		sprintf(soinua, "aplay %s%d.wav", DO, instrumentua);
		system(soinua);

		break;
	case '115'/*s*/:
		sprintf(soinua, "aplay %s%d.wav", RE, instrumentua);
		system(soinua);
		break;
	case '100'/*d*/:
		sprintf(soinua, "aplay %s%d.wav", MI, instrumentua);
		system(soinua);
		break;
	case '102'/*f*/:
		sprintf(soinua, "aplay %s%d.wav", FA, instrumentua);
		system(soinua);
		break;
	case '103'/*g*/:
		sprintf(soinua, "aplay %s%d.wav", SOL, instrumentua);
		system(soinua);
		break;
	case '104'/*h*/:
		sprintf(soinua, "aplay %s%d.wav", LA, instrumentua);
		system(soinua);
		break;
	case '106'/*j*/:
		sprintf(soinua, "aplay %s%d.wav", SI, instrumentua);
		system(soinua);
		break;
	case '112'/*p*/:
		nota = 112;
		break;
	default:
		printf("Sartu aukera egokia bat...\n");
		break;
	}
	return nota;
}

////////////////////////

void abestiaezabatu(KATEA **burua)
{
	KATEA *ptrAux = *burua;

<<<<<<< HEAD
	while (ptrAux != NULL)
	{
		ptrAux = ptrAux->ptrHurrengoa;
		free(*burua);
		*burua = ptrAux;
	}

}
KATEA* sortuNota(int tecla)
{
	KATEA *ptrBerria;

	ptrBerria= (KATEA*)malloc(sizeof(KATEA));

	ptrBerria->tecla = tecla;
	ptrBerria->ptrHurrengoa = NULL;
	return ptrBerria;
}
void zerrendanGorde(int tecla, KATEA**burua)
{
	KATEA *ptrBerria = *burua;

	if (*burua == NULL) *burua = sortuNota(tecla);
	else
	{
		while (ptrBerria->ptrHurrengoa != NULL)
		{
			ptrBerria = ptrBerria->ptrHurrengoa;
		}
		ptrBerria->ptrHurrengoa = sortuNota(tecla);
	}
}
void zerrendaBete(int instrumentua, KATEA**burua)
{
	int tecla;

	while (tecla != 112)
	{
		tecla = notaEskatu();
		erreproduzitu(instrumentua,tecla);
		zerrendanGorde(tecla, burua);
	}
}
void abestiaFitxategianIdatzi(KATEA *burua)
{
	FILE *fitxategia;

	fitxategia = fopen("abestia.txt", "w");
	while (burua != NULL)
	{
		fprintf(fitxategia, "%d\n", burua->tecla);
		burua = burua->ptrHurrengoa;
	}
	fclose(fitxategia);
}
//////////////////

void grabatutakoAbestiaIrakurri(KATEA **burua)
{
	FILE *fitxategia;
	int tecla;
	KATEA *ptrAux,*ptrBerria;

	if (*burua == NULL)
	{
		fitxategia = fopen("abestia.txt", "r");
		while (fscanf(fitxategia, "%d\n", &tecla) != EOF)
		{
			if (*burua == NULL) {				
				ptrBerria = sortuNota(tecla);
				*burua = ptrBerria;
				ptrAux = *burua;
			}
			else
			{
				ptrBerria = sortuNota(tecla);
				while (ptrAux->ptrHurrengoa != NULL)ptrAux = ptrAux->ptrHurrengoa;
				ptrAux->ptrHurrengoa = ptrBerria;

			}
		
		}
		fclose(fitxategia);
	}
}
void grabatutakoaErreproduzitu(KATEA *burua,int instrumentua)
{
	int tecla;
	
	if (burua != NULL)
	{
		while (burua != NULL)
		{
			tecla = burua->tecla;
			erreproduzitu(instrumentua, tecla);
			burua = burua->ptrHurrengoa;
			
		}

	}
	
}
=======
		default:
			printf("Sartu aukera egokia bat...\n");
			break;
		}	
}

void gorde(KATEA **burua)
{
	char str[100];
	
	do {
		printf("Eman tekla bati(0 bukatzeko): ");
		fgets(str, 100, stdin);
		str[strlen(str) - 1] = '\0';
		erreproduzitu(str);
		erreserbatu(str, burua);
	} while (strcmp("0", str) != 0);
}

void erreserbatu(char *str, KATEA **burua)
{
	KATEA *ptraux=*burua;
	
	if (*burua == NULL)
	{
		*burua = (KATEA*)malloc(sizeof(KATEA));
		strcpy((*burua)->tecla, str);
		(*burua)->ptrHurrengoa = NULL;
	}
	else
	{
		while (ptraux->ptrHurrengoa != NULL)ptraux = ptraux->ptrHurrengoa;
		ptraux->ptrHurrengoa = (KATEA*)malloc(sizeof(KATEA));
		strcpy(ptraux->ptrHurrengoa->tecla, str);
		ptraux->ptrHurrengoa->ptrHurrengoa = NULL;
	}
}

void erreproduzituGordetakoa(KATEA *burua)
{
	while (burua != NULL)
	{
		Sleep(500);
		erreproduzitu(burua->tecla);
		burua = burua->ptrHurrengoa;
	}
}
>>>>>>> master
