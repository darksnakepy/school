#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define maxPeople 100
#define cabine 10
#define NPERSONE1 10
#define NPERSONE2 20 
#define NPERSONE3 30
#define NPERSONE4 40

int main()
{
	char nomi[maxPeople];
	char cognomi[maxPeople];
	int giorno[maxPeople], data[maxPeople], anno[maxPeople];
	int cabine4[cabine];

}


void dump()
{
	FILE* fp;
	fp = fopen("giglo", "a");
	if (fp == NULL)
	{
		printf("Errore, nessun database trovato\n");
		exit(1);
	}
	fclose(fp);
}

void read()
{
	FILE* fp; 
	fopen("giglo", "r");
	if (fp == NULL)
	{
		printf("Errore, nessun database trovato\n");
		exit(1);
	}
	fclose(fp);
}

void write()
{
	FILE* fp;
	fopen("giglo", "w");
	if (fp == NULL)
	{
		printf("Errore, nessun database trovato\n");
		exit(1);
	}
}
