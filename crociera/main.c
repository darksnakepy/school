#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define maxPersone 100
#define ncabine 10
#define tipiCabine 4

char codiciCarte[100] =
{
    {"TUGQAJXMCV"},
    {"JFYPNRVIQG"}
};

bool registered = false;
bool cabinePiene = true;
int nPersone = 0; // numero di persone registrate;
int family = 0;
char nomi[maxPersone];
char cognomi[maxPersone];
int day[maxPersone];
int month[maxPersone];
int year[maxPersone];
int cabineOccupate[4];

float prezzoCabine[tipiCabine] = { 99.90, 149.90, 199.90, 249.90 };



int main()
{
    int choice;
    printf("Benvenuto in Costa Crociera\n[0] Registra utente e/o famiglia.\n[1] Utente gia registrato.\n");
    scanf("%d>", &choice);
    do
    {
        switch (choice)
        {
        case 0:
            registerUser();
            break;
        case 1:
            break;
        }
    } while (true);
}

int registerUser()
{
    int choice, i;
    bool cabinFull[4] = false;
    bool isFamily = true;
    if (nPersone < 100)
    {
        printf("Quante persone vogliono acquistare il biglietto?\n");
        scanf("%d", &family);
        nPersone += family;
        if (maxPersone - nPersone < 100)
        {
            for (i = 0; i < nPersone; i++)
            {
                printf("Persona numero [%d], perfavore inserire il nome\n", i);
                scanf("%s> ", &nomi[i]);
                printf("Persona numero [%d], perfavore inserire il cognome\n", i);
                scanf("%s> ", &cognomi[i]);
                printf("Persona numero [%d], inserisci la tua data di nascita (Giorno)\n", i);
                scanf("%s> ", &day[i]);
                if (day[i] > 31 && day[i] < 1)
                {
                    printf("Valore giorno inserito non corretto, reinserisci\n");
                    scanf("%d> ", &day[i]);
                }
                printf("Persona numero [%d], inserisci la tua data di nascita (Mese)\n", i);
                scanf("%d> ", &month[i]);
                while (month[i] > 12 && month[i] < 1)
                {
                    printf("Valore mese inserito non corretto, reinserisci");
                    scanf("%d> ", &month[i]);
                }
                printf("Persona numero [%d], inserisci la tua data di nascita (Anno)\n", i);
                scanf("%d> ", &year[i]);
                while (year[i] > 2022 && month[i] < 1900)
                {
                    printf("Valore anno inserito non corretto, reinserisci\n");
                    scanf("%d> ", &month[i]);
                }
            }
        }
    }
    switch (family)
    {
    case 1:
        if (cabineOccupate[0] <= 10)
        {
            cabineOccupate[0]++;
            break;
        }
        {
            cabinFull[0] = true;
            printf("Non ci sono abbastanza posti\n");
        }
    case 2:
        if (cabineOccupate[1] <= 10)
        {
            cabineOccupate[1]++;
            break;
        }
        else
        {
            cabinFull[1] = true;
            printf("Non ci sono abbastanza posti\n");
        }
    case 3:
        if (cabineOccupate[2] <= 10)
        {
            cabineOccupate[2]++;
            break;
        }
        else
        {
            cabinFull[2] = true;
            printf("Non ci sono abbastanza posti\n");
        }
    case 4:
        if (cabineOccupate[3] <= 10)
        {
            cabineOccupate[3]++;
            break;
        }
        else
        {
            cabinFull[3] = true;
            printf("Non ci sono abbastanza posti\n");
        }
    }
}

void verificaTessera()
{
    char cardInput[] = { "" };
    bool cardOn = true;
    printf("Inserisci il numero della tua tessera\n");
    scanf("%s", cardInput);
    if (strcmp(codiciCarte, cardInput) == 0)
    {
        printf("Codice della carta valido, puoi continuare con gli acquisti\n");
    }
    else
    {
        printf("Codice della carta non valido\n");
    }
}

void prezzoFinale()
{
    
}


int clear()
{
    system("cls");
}

