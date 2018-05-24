#ifndef FUNTZ_H
#define FUNTZ_H

#define MAX_KAR 100

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>

//noten soinuen helbidea
#define DO ".//notak//do"
#define RE ".//notak//re"
#define MI ".//notak//mi"
#define FA ".//notak//fa"
#define SOL ".//notak//sol"
#define LA ".//notak//la"
#define SI ".//notak//si"
//notak
#define Do 97
#define Re 115
#define Mi 100
#define Fa 102
#define Sol 103
#define La 104
#define Si 106
#define BUKATU 112

typedef struct Katea
{
	int tecla;
	clock_t tartea;
	struct Katea* ptrHurrengoa;
}KATEA;

char menua();
int instrumento();
void aukeraExekutatu(char aukera, KATEA ** burua, int instrumentua);
void moduLibrea(int instrumentua);
int notaEskatu();
int erreproduzitu(int instrumentua, int nota);
void abestiaezabatu(KATEA **burua);
KATEA* sortuNota(int tecla, clock_t tartea);
void zerrendanGorde(int tecla, KATEA**burua, clock_t tartea);
int filtro(int tecla);
void zerrendaBete(int instrumentua, KATEA**burua);
void abestiaFitxategianIdatzi(KATEA *burua);
void grabatutakoAbestiaIrakurri(KATEA **burua);
void grabatutakoaErreproduzitu(KATEA *burua, int instrumentua);

#endif
