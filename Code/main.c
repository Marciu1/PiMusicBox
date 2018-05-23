#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "funtzioak.h"

int main(int argc, char **argv)
{
	char aukera = '0';
	KATEA *burua = NULL;
	int instrumentua;

	aukera = menua();
	while (aukera != '0')
	{
		instrumentua = instrumento();
		aukeraExekutatu(aukera, &burua, instrumentua);
		aukera = menua();
	}
	return 0;
}