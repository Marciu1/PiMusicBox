#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>
#include <unistd.h>
#include "funtz.h"

int main(int argc, char **argv)
{
	int instrumentua;
	char aukera = '0';
	KATEA *burua = NULL;

	if (SDL_Init(SDL_INIT_EVERYTHING)!=0)
	{	
		printf("\n Errorea SDL abieraztean.");
	}
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096) < 0)
	{	
		printf("\n Errorea SDL_Mixer abieraztean.");
	}
	else
	{
		aukera = menua();
		while (aukera != '0')
		{
			instrumentua = instrumento();
			aukeraExekutatu(aukera, &burua, instrumentua);
			aukera = menua();
		}
	}
	
	SDL_Quit();
	return 0;
}