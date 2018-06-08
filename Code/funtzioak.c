#include "funtzioak.h"

void pinInit()
{
	wiringPiSetup();

	pinMode(7,INPUT);//7
	pinMode(0,INPUT);//11
	pinMode(1,INPUT);//12
	pinMode(2,INPUT);//13
	pinMode(3,INPUT);//15
	pinMode(4,INPUT);//16
	pinMode(5,INPUT);//18
	pinMode(6,INPUT);//22
	pinMode(21,INPUT);//29
	pinMode(22,INPUT);//31
	pinMode(26,INPUT);//32
	pinMode(23, OUTPUT);
	pinMode(24, OUTPUT);
	pinMode(27, OUTPUT);
	pinMode(25, OUTPUT);
	pinMode(28, OUTPUT);
}

char menua()
{
	sleep(1);
	digitalWrite(23,1);
	char aukera=0;
	int egoera=0;

	/*printf("\n============================================");
	printf("\n|                   MENUA                  |  ");
	printf("\n============================================\n");
	printf("| a: Erreproduzitu.\n");
	printf("| b: Grabatu.\n");
	printf("| d: Grabatutakoa entzun.\n");
	printf("| e: Jokoa\n");
	printf("============================================\n");
	printf("\n 	    Sartu zure aukera: ");*/

	while(egoera==0)
	{
		if(digitalRead(7)==1)
		{
			aukera=1;
			egoera=1;
		}
		if(digitalRead(0)==1)
		{
			aukera=2;
			egoera=1;
		}
		if(digitalRead(1)==1)
		{
			aukera=3;
			egoera=1;
		}
		if(digitalRead(2)==1)
		{
			aukera=4;
			egoera=1;
		}
	}
	sleep(1);
	system("clear");
	digitalWrite(23,0);

	return aukera;
}

int instrumento()
{
	digitalWrite(24,1);
	int instrumentua = 0;

	/*printf("\n ============================================\n");
	printf("                 AUKERAK                    ");
	printf("\n ============================================\n");
	printf("| 1: PIANO\n");
	printf("| 2: 8-BIT\n");
	printf("| 3: BATERIA\n");
	printf("| 4: UKELELE\n");
	printf("===========================================\n");
	printf("\n 	    Sartu zure aukera: ");*/

	while (instrumentua == 0)
	{
		if(digitalRead(7)==1)
		{
			instrumentua=4;
		}
		if(digitalRead(0)==1)
		{
			instrumentua=3;
		}
		if(digitalRead(1)==1)
		{
			instrumentua=2;
		}
		if(digitalRead(2)==1)
		{
			instrumentua=1;
		}
	}
 	sleep(1);
	digitalWrite(24,0);

	return instrumentua;
}

void aukeraExekutatu(char aukera, KATEA **burua, int instrumentua)
{
	sleep(1);

	switch (aukera)
	{
		case 4:
			digitalWrite(27,1);
			/*printf("\n TEKLAK\n");
			printf("a-->DO s-->RE d-->MI f-->FA g-->SOL h-->LA j-->SI//gelditzeko 0 sakatu");
			printf("\n");*/
			moduLibrea(instrumentua);
			digitalWrite(27,0);
			break;
		case 3:
			digitalWrite(25,1);
			/*printf("\n TEKLAK\n");
			printf("a-->DO s-->RE d-->MI f-->FA g-->SOL h-->LA j-->SI//grabaketa bukatzeko 'p' sakatu");
			printf("\n");*/
			zerrendaBete(instrumentua, burua);
			abestiaFitxategianIdatzi(*burua);
			digitalWrite(25,0);
			break;
		case 2:
			digitalWrite(28,1);
			grabatutakoAbestiaIrakurri(burua);
			grabatutakoaErreproduzitu(*burua, instrumentua);
			digitalWrite(28,0);
			break;
		case 1:

			game(instrumentua);
			digitalWrite(27,0);
			digitalWrite(25,0);
			digitalWrite(28,0);
			break;
		default:
			break;
		sleep(1);
	}
}

void moduLibrea(int instrumentua)
{
	int  nota=-1;
	EGOERA egoera;

	while (nota != 8)
	{
		egoera = zeinNota(&nota, egoera, instrumentua);
	}
}

EGOERA zeinNota(int *nota, EGOERA egoera, int instrumentua)
{
	egoera=nullJarri(egoera);

	if((digitalRead(3)==1)&&(egoera.egoera1==0))
	{
		*nota=Si;
		forkFuntzioa(instrumentua,*nota);
		egoera.egoera1=1;
		egoera.egoeraGen=1;

	}
	if((digitalRead(4)==1)&&(egoera.egoera2==0))
	{

		*nota=La;
		forkFuntzioa(instrumentua,*nota);
		egoera.egoera2=1;
		egoera.egoeraGen=1;
	}
	if((digitalRead(5)==1)&&(egoera.egoera3==0))
	{

		*nota=Sol;
		forkFuntzioa(instrumentua,*nota);
		egoera.egoera3=1;
		egoera.egoeraGen=1;
	}
	if((digitalRead(6)==1)&&(egoera.egoera4==0))
	{

		*nota=Fa;
		forkFuntzioa(instrumentua,*nota);
		egoera.egoera4=1;
		egoera.egoeraGen=1;
	}
	if((digitalRead(21)==1)&&(egoera.egoera5==0))
	{

		*nota=Mi;
		forkFuntzioa(instrumentua,*nota);
		egoera.egoera5=1;
		egoera.egoeraGen=1;
	}
	if((digitalRead(22)==1)&&(egoera.egoera6==0))
	{

		*nota=Re;
		forkFuntzioa(instrumentua,*nota);
		egoera.egoera6=1;
		egoera.egoeraGen=1;
	}
	if((digitalRead(26)==1)&&(egoera.egoera7==0))
	{
		*nota=Do;
		forkFuntzioa(instrumentua,*nota);
		egoera.egoera7=1;
		egoera.egoeraGen=1;
	}
	if(digitalRead(7)==1)
	{
		*nota=Bukatu;
		egoera.egoeraGen=1;
	}

	return egoera;
}

EGOERA nullJarri(EGOERA egoera)
{
		if(digitalRead(3)==0)egoera.egoera1=0;
		if(digitalRead(4)==0)egoera.egoera2=0;
		if(digitalRead(5)==0)egoera.egoera3=0;
		if(digitalRead(6)==0)egoera.egoera4=0;
		if(digitalRead(21)==0)egoera.egoera5=0;
		if(digitalRead(22)==0)egoera.egoera6=0;
		if(digitalRead(26)==0)egoera.egoera7=0;

		return egoera;
}

int erreproduzitu(int instrumentua, int nota)
{
	char soinua[100];

	switch (nota)
	{
		case Do:
			sprintf(soinua, "aplay %s%d.wav", DO, instrumentua);
			system(soinua);
			break;
		case Re:
			sprintf(soinua, "aplay %s%d.wav", RE, instrumentua);
			system(soinua);
			break;
		case Mi:
			sprintf(soinua, "aplay %s%d.wav", MI, instrumentua);
			system(soinua);
			break;
		case Fa:
			sprintf(soinua, "aplay %s%d.wav", FA, instrumentua);
			system(soinua);
			break;
		case Sol:
			sprintf(soinua, "aplay %s%d.wav", SOL, instrumentua);
			system(soinua);
			break;
		case La:
			sprintf(soinua, "aplay %s%d.wav", LA, instrumentua);
			system(soinua);
			break;
		case Si:
			sprintf(soinua, "aplay %s%d.wav", SI, instrumentua);
			system(soinua);
			break;
		case Bukatu:
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
	*burua=NULL;
}

KATEA* sortuNota(int tecla, long tartea)
{
	KATEA *ptrBerria;

	ptrBerria= (KATEA*)malloc(sizeof(KATEA));

	ptrBerria->tecla = tecla;
	ptrBerria->tartea = tartea;
	ptrBerria->ptrHurrengoa = NULL;
	return ptrBerria;
}

void zerrendanGorde(int tecla, KATEA**burua, long tartea)
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
	int tecla, egoera;
	long  tartea;
	struct timeval hasiera,bukaera;

	if(*burua!=NULL)
	{
		abestiaezabatu(burua);
	}

	while (tecla != 8)
	{
		egoera=0;
		gettimeofday(&hasiera, NULL);
		while(egoera==0)
		{
			egoera = notaJokua(&tecla, egoera);
		}
		gettimeofday(&bukaera, NULL);
		tartea=(bukaera.tv_sec-hasiera.tv_sec)*1000000+(bukaera.tv_usec-hasiera.tv_usec);
		erreproduzitu(instrumentua, tecla);
		zerrendanGorde(tecla, burua, tartea);
	}
}

void abestiaFitxategianIdatzi(KATEA *burua)
{
	FILE *fitxategia;

	fitxategia = fopen("abestia.txt", "w");
	while (burua != NULL)
	{
		fprintf(fitxategia, "%d %li\n", burua->tecla,burua->tartea);
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
		while (fscanf(fitxategia, "%d %li\n", &tecla, &tartea) != EOF)
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
	float tartea;

	while (burua != NULL)
	{
		tecla = burua->tecla;
		tartea=(float)burua->tartea /1000000;
		sleep(tartea);
		erreproduzitu(instrumentua, tecla);
		burua = burua->ptrHurrengoa;
	}
}


void forkFuntzioa(int instrumentua, int nota)
{
	int pid=fork();

	if(pid==-1)printf("errore bat fork");
	else if(pid==0)
	{
		erreproduzitu(instrumentua, nota);
		exit(0);

	}
}
void game(int instrumentua)
{
	int i=-1, e, nota, notakMak[50],notakJok[50], egoera=0, correct =1;
	char soinua[100];

	while(correct==1){
		i++;
		//makina
		digitalWrite(27,1);
		digitalWrite(25,1);
		digitalWrite(28,1);
		sprintf(soinua, "aplay .//Soinuak//empezar.wav");
		system(soinua);
		sleep(1);
		for(e=0;e<=i;e++)
		{
			nota=rand() % 7 +1;
			erreproduzitu(instrumentua, nota);
			*(notakMak+e)=nota;
			sleep(1);
		}
		//jokalaria
		digitalWrite(27,0);
		digitalWrite(25,0);
		sprintf(soinua, "aplay .//Soinuak//empezar.wav");
		system(soinua);
		for(e=0;e<=i;e++)
		{
			egoera=0;
			while(egoera==0)
			{
				egoera=notaJokua(&nota, egoera);
			}
			erreproduzitu(instrumentua, nota);
			*(notakJok+e)=nota;
		}
		for(e=0;e<=i;e++)
		{
			if(*(notakMak+e)!=*(notakJok+e))correct=0;
		}
		if(correct==0)
		{
			digitalWrite(28,0);
			digitalWrite(25,1);
			digitalWrite(27,0);
			sprintf(soinua, "aplay .//Soinuak//incorrect.wav");
			system(soinua);
		}
		else
		{
			digitalWrite(27,1);
			digitalWrite(25,0);
			digitalWrite(28,0);
			sprintf(soinua, "aplay .//Soinuak//correct.wav");
			system(soinua);
		}
		sleep(2);
	}
}

int notaJokua(int *nota, int egoera)
{
	if(digitalRead(3)==1)
	{
		*nota=Si;
		egoera=1;
	}
	if(digitalRead(4)==1)
	{
		*nota=La;
		egoera=1;
	}
	if(digitalRead(5)==1)
	{
		*nota=Sol;
		egoera=1;
	}
	if(digitalRead(6)==1)
	{
		*nota=Fa;
		egoera=1;
	}
	if(digitalRead(21)==1)
	{
		*nota=Mi;
		egoera=1;
	}
	if(digitalRead(22)==1)
	{
		*nota=Re;
		egoera=1;
	}
	if(digitalRead(26)==1)
	{
		*nota=Do;
		egoera=1;
	}
	if(digitalRead(7)==1)
	{
		*nota=Bukatu;
		egoera=1;
	}

	return egoera;
}
