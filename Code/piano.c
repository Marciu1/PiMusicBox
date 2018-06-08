#include "funtzioak.h"

int main(int argc, char **argv)
{
	int instrumentua;
	char aukera = '0';
	KATEA *burua = NULL;

	pinInit();

	aukera = menua();
	while (aukera != '0')
	{
		instrumentua = instrumento();
		aukeraExekutatu(aukera, &burua, instrumentua);
		aukera = menua();
	}
	return 0;
}

