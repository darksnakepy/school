#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// dichiaro funzioni 
void clear();
void database();
void acquisto();

// variabili costanti
#define maxPersone 100
#define ncabine 10
#define tipiCabine 4

int totFamiglie = 0;
bool registered = false;
bool cabinePiene = false;
int nPersone = 0; // numero di persone registrate
int family = 0;
char nomi[maxPersone];
char cognomi[maxPersone];
int day[maxPersone];
int month[maxPersone];
int year[maxPersone];
int lungFamiglia[maxPersone];
int familyCont = 0;
int cabineOccupate[4];
float prezzoFinale[maxPersone];


int main()
{
    srand(time(NULL));
    int choice;
    printf("\n Benvenuto nel programma di registrazione di Costa Crociera!\n [0] Registra utente e/o famiglia\n [1] Gestione staff\n\n >");
    scanf("%d", &choice);
    do
    {
        switch (choice)
        {
        case 0:
            registerUser();
            break;
        case 1:
            acquisto();
            break;
        case 2:
            break;

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
        if (cabinePiene == false)
        {
            printf("[0] Registra famiglia o custom\n[1] Viaggia\n[3] Torna indietro\n");
        }
        if (nPersone < 100)
        {
            scanf("%d", &choice);  
            clear();
            if (choice == 0 && nPersone < 100)
            {
                printf("Inserisci il numero di utenti che vuoi registrare\n");
                scanf("%d", &family);
                nPersone += family;
                if (maxPersone - nPersone < 100)
                {
                    for (i = totFamiglie ; i < family + totFamiglie; i++)
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
                            printf("Valore mese inserito non corretto, reinserisci\n");
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

                    switch (family)
                    {
                    case 1:
                        if (cabineOccupate[0] <= 10)
                        {
                            cabineOccupate[0]++;
                            lungFamiglia[familyCont] = family;
                            familyCont++;
                            nPersone += family;
                            totFamiglie += family;
                            break;
                        }
                        else
                        {
                            cabinFull[0] = true;
                            printf("Non ci sono abbastanza posti\n");
                        }
                        break;
                    case 2:
                        if (cabineOccupate[1] <= 10)
                        {
                            cabineOccupate[1]++;
                            lungFamiglia[familyCont] = family;
                            familyCont++;
                            nPersone += family;
                            totFamiglie += family;
                            break;
                        }
                        else
                        {
                            cabinFull[1] = true;
                            printf("Non ci sono abbastanza posti\n");
                        }
                        break;
                    case 3:
                        if (cabineOccupate[2] <= 10)
                        {
                            cabineOccupate[2]++;
                            lungFamiglia[familyCont] = family;
                            familyCont++;
                            nPersone += family;
                            totFamiglie += family;
                            break;
                        }
                        else
                        {
                            cabinFull[2] = true;
                            printf("Non ci sono abbastanza posti\n");
                        }
                        break;
                    case 4:
                        if (cabineOccupate[3] <= 10)
                        {
                            cabineOccupate[3]++;
                            lungFamiglia[familyCont] = family;
                            familyCont++;
                            nPersone += family;
                            totFamiglie += family;
                            break;
                        }
                        else
                        {
                            cabinFull[3] = true;
                            printf("Non ci sono abbastanza posti\n");
                        }
                        break;
                    default:
                        printf("Errore");
                        break;
                    }

                    if (cabinFull[0] && cabinFull[1] && cabinFull[2] && cabinFull[3])
                    {
                        cabinePiene = true;
                    }
                }
            }
            else if(choice == 1)
            {
                printf("Perfetto, Buon viaggio!");
                Sleep(1000);
                main();
            }
            else if(choice==3)
            {
                main();
            }
            else
            {
                printf("Scelta sbagliata!\n");
                Sleep(5000);
                registerUser();
            }
        }
    
    }while (true);
}


void database()
{
    int spesaFamiglia = 0;

    for (int i = 0; i < 4; i++)
    {
        printf("Cabine da : [%d] persone - occupate da [%d]\n", i + 1, cabineOccupate[i]);
    }
    if (cabinePiene = true)
    {
        printf("La nave e' al completo!\n");
    }
    for (int i = 0; i < familyCont; i++)
    {
        for (int j = 0; j < lungFamiglia[i]; j++)
        {
            printf("[%d] Persona: \n", i + 1);
            printf("Nome: [%s]\nCognome: [%s] \n", nomi[i], cognomi[i]);
            printf("Data di nascita persona numero [%d]: %d %d %d", day[i], month[i], year[i]);
            printf("Prezzo speso %.2f: ", spesaFamiglia);
            spesaFamiglia = 0.0f;
            
        }
    }

}

void acquisto()
{
    for (int i = 0; i < nPersone; i++)
    {
        prezzoFinale[i] = ((double)rand() / RAND_MAX) * 400;
    }
}


void clear()
{
    system("cls");
}


