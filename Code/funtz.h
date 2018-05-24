#ifndef FUNTZ_H
#define FUNTZ_H

#define MAX_KAR 128
#define MAX_SOUNDS 15
#define MAX_NOTAK 15

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>
#include <unistd.h>

//noten soinuen helbidea
#define DO ".//Soinuak//do"
#define RE ".//Soinuak//re"
#define MI ".//Soinuak//mi"
#define FA ".//Soinuak//fa"
#define SOL ".//Soinuak//sol"
#define LA ".//Soinuak//la"
#define SI ".//Soinuak//si"
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

void audioInit();
int loadSound(char *fileName);
int loadTheMusic(char *fileName);
int playSound(int idSound,int channel);
int playMusic(void);
void toggleMusic(void);
void musicUnload(void);
void soundsUnload();
void audioTerminate(void);
void initSound();

#endif