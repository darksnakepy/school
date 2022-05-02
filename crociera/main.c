#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define maxPersone 100
#define ncabine 10
#define tipiCabine 4

char codiciCarte[100];

bool registered = false;
bool cabinePiene = false;
int nPersone = 0; // numero di persone registrate;
int family = 0;
char nomi[maxPersone];
char cognomi[maxPersone];
int day[maxPersone];
int month[maxPersone];
int year[maxPersone];
int cabineOccupate[4];
void gestioneCabine();

float prezzoCabine[tipiCabine] = { 99.90, 149.90, 199.90, 249.90 };

int main()
{
    int choice;
    printf("Benvenuto in Costa Crociera!\n[0] Registra utente e/o famiglia\n[1] Bar\n[2] Gestione staff\n>");
    scanf("%d", &choice);
    do
    {
        switch (choice)
        {
        case 0:
            registerUser();
            break;
        case 1:
            break;
        case 2:
            gestioneCabine();

        default:
            printf("Errore\n");
            break;
        }
        
    } while (true);
}

int registerUser()
{
    clear();
    int choice, i;
    bool cabinFull[4];
    bool isFamily = true;
    do
    {
        if (nPersone < 100)
        {
            printf("[0] Registra un gruppo familiare\n[1] Registra singole persone");
            scanf("%d", &choice);
            if (nPersone < 100 && choice == 0)
            {
                do
                {
                    scanf("%d", &family);
                    nPersone += family;
                    if (maxPersone - nPersone < 100)
                    {
                        scanf("%d", &choice);
                        if (choice)
                            for (i = 0; i < nPersone; i++)
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
                            }
                        break;
                    }
                    printf("Registrazione effettuata!\n");

                    switch (family)
                    {
                    case 1:
                        if (cabineOccupate[0] <= 10)
                        {
                            cabineOccupate[0]++;
                            break;
                        }
                        else
                        {
                            cabinFull[0] = true;
                            printf("Non ci sono abbastanza posti\n");
                            break;
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
            } while (cabinePiene = false || family < 4);

            else
            {
                cabinePiene = true;
                nPersone -= family;
                printf("Non ci sono posti liberi.\n");
                clear();
            }
            
            
    } while (true);
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

void gestioneCabine()
{
    for (int i = 0; i < 4; i++)
    {
        printf("Cabine : [%d]\n", i, cabineOccupate[i]);
    }
    if (cabinePiene = true)
    {
        printf("Le cabine sono piene!\n");
    }
    
}



int clear()
{
    system("cls");
}

