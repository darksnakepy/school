#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define maxPersone 100
#define ncabine 10
#define tipiCabine 4

char codiciCarte[100];

int totFamiglie;
bool registered = false;
bool cabinePiene = false;
int nPersone = 0; // numero di persone registrate
int family = 0;
char nomi[maxPersone];
char cognomi[maxPersone];
int day[maxPersone];
int month[maxPersone];
int year[maxPersone];
int cabineOccupate[4];
void outPersone();


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
            outPersone();
            break;

        default:
            printf("Errore\n");
            break;
        }

    } while (true);
}

int registerUser()
{
    int choice, i;
    bool cabinFull[4];
    bool isFamily = true;
    do
    {
        if (cabinePiene == false)
        {
            printf("[0] Custom\n[1] Registra una famiglia\n");
        }
        if (nPersone < 100)
        {
            scanf("%d", &choice);

            if (choice == 0 && nPersone < 100)
            {
                do
                {
                    printf("Inserisci il numero di utenti che vuoi registrare\n");
                    scanf("%d", &family);
                    nPersone += family;
                    if (maxPersone - nPersone < 100)
                    {
                        for (i = totFamiglie ; i < nPersone - totFamiglie; i++)
                        {
                            printf("Persona numero [%d], perfavore inserire il nome\n", i);
                            scanf("%s> ", &nomi[i]);
                            printf("Persona numero [%d], perfavore inserire il cognome\n", i);
                            scanf("%s> ", &cognomi[i]);
                            printf("Persona numero [%d], inserisci la tua data di nascita (Giorno)\n", i);
                            scanf("%s> ", &day[i]);
                            if (day[i] < 1 || day[i] > 31)
                            {
                                printf("Valore giorno inserito non corretto, reinserisci\n");
                                scanf("%d> ", &day[i]);
                            }
                            printf("Persona numero [%d], inserisci la tua data di nascita (Mese)\n", i);
                            scanf("%d> ", &month[i]);
                            while (month[i] < 1 || month[i] > 12)
                            {
                                printf("Valore mese inserito non corretto, reinserisci");
                                scanf("%d> ", &month[i]);
                            }
                            printf("Persona numero [%d], inserisci la tua data di nascita (Anno)\n", i);
                            scanf("%d> ", &year[i]);
                            while (year[i] < 1900 || year[i] > 2022)
                            {
                                printf("Valore anno inserito non corretto, reinserisci\n");
                                scanf("%d> ", &month[i]);
                            }
                        }
                        totFamiglie += family;
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
                        default:
                            printf("Errore");
                            break;
                        }

                        if (cabinFull[0] && cabinFull[1] && cabinFull[2] && cabinFull[3])
                        {
                            cabinePiene = true;
                        }
                    }

                } while (true);
            }
        }
    
    }while (true);
}


void outPersone()
{
    for (int i = 0; i < 4; i++)
    {
        printf("Cabine da : [%d] - occupate da \n", i + 1, cabineOccupate[i]);
    }
    if (cabinePiene = true)
    {
        printf("Le cabine sono piene!\n");
    }
    for (int i = 0; i < nPersone; i++)
    {
        printf("[%d]\n", i+1);
        printf("Nome: [%s]\nCognome: [%s] \n");
        printf("Data di nascita persona numero [%d]: %d %d %d", day[i], month[i], year[i]);
    }
}

void clear()
{
    system("cls");
}


