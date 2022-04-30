#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define maxPersone 100
#define ncabine 10
#define tipiCabine 4

char path[] = { "file.txt" };

bool registered = false;
bool cabinePiene = true;
int nPersone = 0; // numero di persone registrate;
int familyMembers = 0;
char nomi[maxPersone];
char cognomi[maxPersone];
int day[maxPersone];
int month[maxPersone];
int year[maxPersone];
int cabineOccupate4[ncabine]; // cabine per 4 
int cabineOccupate3[ncabine];//cabine per 3
int cabineOccupate2[ncabine];//cabine per 2
int cabineOccupate1[ncabine]; //cabine singole
void write();
void read();
void createFile();

float prezzoCabine[tipiCabine] = {99.90, 149.90, 199.90, 249.90};



int main()
{
    createFile();
    int choice;
    printf("Benvenuto in Costa Crociera\n[0] Registra utente e/o famiglia.\n[1] Utente gia registrato.\n");
    scanf("%d", &choice);
    do
    {
        switch (choice)
        {
        case 0:
            registerUser();
            break;
        case 1:
            assegnaCabine();
            break;
        }
    } while (true);
}

int registerUser()
{
    int choice, i;
    if (nPersone < 100)
    {
        printf("Quante persone vogliono acquistare il biglietto\n");
        scanf("%d", &familyMembers);
        nPersone += familyMembers;
        if (maxPersone - nPersone < 100)
        {
          for (i = 0; i < familyMembers; i++)
                {
                    printf("Persona numero [%d], perfavore inserire il nome\n", i);
                    scanf("%s> ", &nomi[i]);
                    printf("Persona numero [%d], perfavore inserire il cognome\n", i);
                    scanf("%s> ", &cognomi[i]);
                    printf("Persona numero [%d], inserisci la tua data di nascita (Giorno)\n", i);
                    scanf("%s> ", &day[i]);
                    if (day[i] > 31 || day[i] < 1)
                    {
                        printf("Valore giorno inserito non corretto, reinserisci\n");
                        scanf("%d> ", &day[i]);
                    }
                    printf("Persona numero [%d], inserisci la tua data di nascita (Mese)\n", i);
                    scanf("%d> ", &month[i]);
                    while (month[i] > 12 || month[i] < 1)
                    {
                        printf("Valore mese inserito non corretto, reinserisci");
                        scanf("%d> ", &month[i]);
                    }
                    printf("Persona numero [%d], inserisci la tua data di nascita (Anno)\n", i);
                    scanf("%d> ", &year[i]);
                    while (year[i] > 2022 || month[i] < 1900)
                    {
                        printf("Valore anno inserito non corretto, reinserisci\n");
                        scanf("%d> ", &month[i]);

                    }
                    write();
                }
            }
        }
    }
    


int utenteRegistrato()
{
    printf("Se sei un utente gia registrato, inserisci il nome e cognome per verificare la validità del tuo biglietto\n");
}



int assegnaCabine()
{
    for (int i = 0; i < 4; i++)
    {
        printf("%.2f\n%.2f\n%.2f\n%.2f", prezzoCabine[i]);

    }

}



int clear()
{
    system("cls");
}

void write()
{
    FILE* file;
    file = fopen(path, "w");
    if (file == NULL)
    {
        printf("Errore, nessun database trovato\n");
        exit(1);
    }
    for (int i = 0; i < nomi; i++)
    {
        fprintf(file, "%s ", nomi[i]);
    }
    for (int i = 0; i < cognomi; i++)
    {
        fprintf(file, "%s\n", cognomi[i]);
    }
    fclose(file);
}
void read()
{
    FILE* fp;
    fp = fopen(path, "r");
    if (fp == NULL)
    {
        printf("Errore, nessun database trovato\n");
        exit(1);
    }
    for (int i = 0; i < nomi; i++)
    {
        fscanf(fp, "%s", &nomi[i]);
    }
    for (int i = 0; i < cognomi; i++)
    {
        fscanf(fp, "%s", &cognomi[i]);
    }

    fclose(fp);
}
void createFile()
{
    FILE* fp;
    fp = fopen(path, "a");
    if (fp == NULL)
    {
        printf("Errore, nessun database trovato\n");
        exit(1);
    }
    fclose(fp);
}
