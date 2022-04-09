#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define totPers 100
#define ncabine 10


bool registrato = false;
bool pieno = false;
int nPersone = 0; // numero di persone registrate;
int familyMembers = 0;
char nomi[totPers];
char cognomi[totPers];
int day[totPers];
int month[totPers];
int year[totPers]; 
int cabineOccupate4[ncabine]; // cabine per 4 
int cabineOccupate3[ncabine];//cabine per 3
int cabineOccupate2[ncabine];//cabine per 2
int cabineOccupate1[ncabine]; //cabine singole

int main()
{
    printf("Benvenuto in Costa Crociera;");
    do
    {
        switch(choice)
        {
            case 0:
                register();
                break;
            case 1:
                break;                
        }
    }while(true);
}

void register()
{
    int choice, i;
    if(nPersone < 100)
    {
        printf("Quante persone vogliono acquistare il biglietto\n");
        scanf(&d, familyMembers);
        nPersone += familyMembers;
        if (totPers - nPersone > 100)
        {  
            for(i = 0; i<familyMembers; i++)
            {
                printf("Persona numero [%d], perfavore inserire il nome\n", i);
                scanf("%s> ", &nomi[i]);
                printf("Persona numero [%d], perfavore inserire il cognome\n", i);
                scanf("%s> ", &cognomi[i]);
                printf("Persona numero [%d], inserisci la tua data di nascita (Giorno)\n", i);
                scanf("%s> ", &day[i]);
                while(day[i] > 31 || day[i] < 1)
                {
                    printf("Valore non corretto, riprova\n");
                    scanf("%d> ", &day[i]);
                }
                printf("Persona numero [%d], inserisci la tua data di nascita (Mese)\n", i);
                scanf("%d> ", &month[i]);
                while(month[i] > 12 || month[i] < 1)
                {
                    printf("Valore non corretto, riprova");
                    scanf("%d> ", &month[i]);
                }
                printf("Persona numero [%d], inserisci la tua data di nascita (Anno)\n", i);
                scanf("%d> ", &year[i]);
                while(year[i] > 2022 || month[i] < 1900)
                {
                    printf("Valore non corretto, riprova\n");
                    scanf("%d> ", &month[i]);
                } 
            }
        }
    }
    
    
}



void clear()
{
    system("clear");
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
