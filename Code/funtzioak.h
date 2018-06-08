#ifndef FUNTZIOAK_H
#define FUNTZIOAK_H

#define MAX_KAR 128
#define MAX_SOUNDS 15
#define MAX_NOTAK 15

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <wiringPi.h>
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
#define Do 1
#define Re 2
#define Mi 3
#define Fa 4
#define Sol 5
#define La 6
#define Si 7
#define Bukatu 8

typedef struct egoera
{
	int egoera1;
	int egoera2;
	int egoera3;
	int egoera4;
	int egoera5;
	int egoera6;
	int egoera7;
	int egoeraGen;

}EGOERA;

typedef struct Katea
{
	int tecla;
	long tartea;
	struct Katea* ptrHurrengoa;
}KATEA;

void pinInit();
char menua();
int instrumento();
void aukeraExekutatu(char aukera, KATEA ** burua, int instrumentua);
void moduLibrea(int instrumentua);
EGOERA zeinNota(int *nota, EGOERA egoera, int instrumentua);
EGOERA notaHartu(int *nota, EGOERA egoera, int instrumentua);
EGOERA nullJarri(EGOERA egoera);
void forkFuntzioa( int instrumentua,int nota);
void abestiaezabatu(KATEA **burua);
void game(int instrumentua);
int notaJokua(int *nota, int egoera);

//

KATEA* sortuNota(int tecla, long tartea);
void zerrendanGorde(int tecla, KATEA**burua, long tartea);
int filtro(int tecla);
void zerrendaBete(int instrumentua, KATEA**burua);
void abestiaFitxategianIdatzi(KATEA *burua);
void grabatutakoAbestiaIrakurri(KATEA **burua);
void grabatutakoaErreproduzitu(KATEA *burua, int instrumentua);

#endif
