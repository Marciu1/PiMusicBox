#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>
#include <unistd.h>
#include "funtz.h"

char menua()
{
	char aukera;
	char str[MAX_KAR];

	printf("\n ============================================");
	printf("\n |                   MENUA                  |  ");
	printf("\n ============================================\n");
	printf(" | a: Erreproduzitu.\n");
	printf(" | b: Grabatu.\n");
	printf(" | d: Grabatutakoa entzun.\n");
	printf(" | 0: Irten\n");
	printf("===========================================\n");
	printf("\n 	    Sartu zure aukera: ");
	fgets(str, MAX_KAR, stdin);
	sscanf(str, "%c", &aukera);

	return aukera;
}

int instrumento()
{
	int instrumentua = 0;
	char str[MAX_KAR];

	do {
		printf("\n ============================================");
		printf("\n |                 AUKERAK                  |  ");
		printf("\n ============================================\n");
		printf(" | 1: Pianoa\n");
		printf(" | 2: 8-Bit\n");
		printf(" | 3: Tronpeta\n");
		printf(" | 4: Gehigarriak\n");
		printf("===========================================\n");
		printf("\n 	    Sartu zure aukera: ");
		fgets(str, MAX_KAR, stdin);
		sscanf(str, "%d", &instrumentua);
		if((instrumentua >0) || (instrumentua < 5))
		{
			printf(" Sartu aukera egoki bat.\n");
		}
	} while ((instrumentua < 0) && (instrumentua > 5));

	return instrumentua;
}

void aukeraExekutatu(char aukera, KATEA **burua, int instrumentua)
{
	switch (aukera)
	{
	case 'a':
		printf("\n TEKLAK\n");
		printf(" a-->DO s-->RE d-->MI f-->FA g-->SOL h-->LA j-->SI//gelditzeko 0 sakatu");
		moduLibrea(instrumentua);
		break;
	case 'b':
		printf("\n TEKLAK\n");
		printf("a-->DO s-->RE d-->MI f-->FA g-->SOL h-->LA j-->SI//grabaketa bukatzeko 'p' sakatu");
		zerrendaBete(instrumentua, burua);
		abestiaFitxategianIdatzi(*burua);
		break;
	case 'd':
		grabatutakoaErreproduzitu(*burua, instrumentua);
		break;
	default:
		printf("Sartu aukera egokia bat...\n");
		break;
	}
}

void moduLibrea(int instrumentua)
{
	int tecla=1;

	while (tecla != '0')
	{
		tecla = notaEskatu();
		erreproduzitu(instrumentua,tecla);
	}
}

int notaEskatu()
{
	char str[MAX_KAR];
	char nota;

	printf("\n Jo hurrengo tekla: ");
	fgets(str, MAX_KAR, stdin);
	str[strlen(str)-1]='\0';
	sscanf(str, "%c", &nota);

	return nota;
}

int erreproduzitu(int instrumentua, int nota)
{
	Mix_Chunk *sonido;
	char soinua[MAX_KAR];

	switch (nota)
	{
	case 97/*a*/:
		sprintf(soinua, "%s%d.wav", DO, instrumentua);
		sonido=Mix_LoadWAV(soinua);
		Mix_VolumeChunk(sonido, 10);
		Mix_AllocateChannels(7);
		Mix_PlayChannel(1, sonido, 0);

		break;
	case 115 /*s*/:
		sprintf(soinua, "aplay %s%d.wav", RE, instrumentua);
		system(soinua);
		break;
	case 100 /*d*/:
		sprintf(soinua, "aplay %s%d.wav", MI, instrumentua);
		system(soinua);
		break;
	case 102 /*f*/:
		sprintf(soinua, "aplay %s%d.wav", FA, instrumentua);
		system(soinua);
		break;
	case 103 /*g*/:
		sprintf(soinua, "aplay %s%d.wav", SOL, instrumentua);
		system(soinua);
		break;
	case 104 /*h*/:
		sprintf(soinua, "aplay %s%d.wav", LA, instrumentua);
		system(soinua);
		break;
	case 106 /*j*/:
		sprintf(soinua, "aplay %s%d.wav", SI, instrumentua);
		system(soinua);
		break;
	case 112 /*p*/:
		nota = 112;
		break;
	default:
			break;
	}
	return nota;
}

//////////////////
void abestiaezabatu(KATEA **burua)
{
	KATEA *ptrAux = *burua;

	while (ptrAux != NULL)
	{
		ptrAux = ptrAux->ptrHurrengoa;
		free(*burua);
		*burua = ptrAux;
	}
}

KATEA* sortuNota(int tecla, clock_t tartea)
{
	KATEA *ptrBerria;

	ptrBerria= (KATEA*)malloc(sizeof(KATEA));

	ptrBerria->tecla = tecla;
	ptrBerria->tartea = tartea;
	ptrBerria->ptrHurrengoa = NULL;
	return ptrBerria;
}

void zerrendanGorde(int tecla, KATEA**burua, clock_t tartea)
{
	KATEA *ptrBerria = *burua;

	if (*burua == NULL)
	{
		*burua = sortuNota(tecla, tartea);
	}
	else
	{
		while (ptrBerria->ptrHurrengoa != NULL)
		{
			ptrBerria = ptrBerria->ptrHurrengoa;
		}
		ptrBerria->ptrHurrengoa = sortuNota(tecla, tartea);
	}
}

void zerrendaBete(int instrumentua, KATEA**burua)
{
	int tecla;
	clock_t hasiera, bukaera;

	if(burua!=NULL){
		abestiaezabatu(burua);
	}

	while (tecla != 112)
	{
		hasiera = clock();
		tecla = notaEskatu();
		bukaera = clock();
		if(filtro(tecla)==1)
		{
			erreproduzitu(instrumentua, tecla);
			zerrendanGorde(tecla, burua, bukaera-hasiera);
		}
		else printf("\n Sartu aukera egoki bat\n");
	}
}

int filtro(int tecla)
{
	int egoera=0;

	if((tecla==97) || (tecla==115) || (tecla==100) || (tecla==102) || (tecla==103) || (tecla==104) || (tecla==106))
	{
		egoera = 1;
	}

	return egoera;
}

void abestiaFitxategianIdatzi(KATEA *burua)
{
	FILE *fitxategia;

	fitxategia = fopen("abestia.txt", "w");
	while (burua != NULL)
	{
		fprintf(fitxategia, "%d %ld\n", burua->tecla,burua->tartea);
		burua = burua->ptrHurrengoa;
	}
	fclose(fitxategia);
}

//////////////////
void grabatutakoAbestiaIrakurri(KATEA **burua)
{
	int tecla;
	FILE *fitxategia;
	clock_t tartea;
	KATEA *ptrAux,*ptrBerria;

	if (*burua == NULL)
	{
		fitxategia = fopen("abestia.txt", "r");
		while (fscanf(fitxategia, "%d %ld\n", &tecla, &tartea) != EOF)
		{
			if (*burua == NULL)
			{
				ptrBerria = sortuNota(tecla, tartea);
				*burua = ptrBerria;
				ptrAux = *burua;
			}
			else
			{
				ptrBerria = sortuNota(tecla,tartea);
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
			sleep(burua->tartea/1000);
			burua = burua->ptrHurrengoa;
		}
	}
}
