#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// dichiaro funzioni 
void clear();
void output();
void acquisto();
float gucci();
float shop();
float bar();
int trovaPersone();

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
bool cont = true;


int main()
{
    clear();
    int choice;
    printf("\n Benvenuto nel programma di registrazione di Costa Crociera!\n [0] Registra utente e/o famiglia\n [1] Bar \n [2] Gestione staff\n\n >");
    scanf("%d", &choice);
    do
    {
        switch (choice)
        {
        case 0:
            registerUser();
            break;
        case 1:
            shop();
            break;
        case 2:
            output();
            break;

        default:
            printf("Errore\n");
            break;
        }

    } while (cont);
}

int registerUser()
{

    int choice, i;
    bool cabinFull[4];

    do
    {
        clear();
        if (nPersone < 100)
        {
            if (cabinePiene == false)
            {
                printf("[0] Registra famiglia o custom\n");
            }
            printf("[1] Parti\n");
            printf("[2] Torna indietro\n");
            scanf("%d", &choice);
            if (choice == 0 && nPersone < 100 && cabinePiene == false)
            {
                do
                {
                    printf("Inserisci il numero di utenti che vuoi registrare\n>");
                    scanf("%d", &family);

                } while (family < 0 || family > 4);
                ;
                if (cabinePiene == false)
                {
                    for (i = totFamiglie; i < family + totFamiglie; i++)
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
                        if (cabineOccupate[0] < 10)
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
                        if (cabineOccupate[1] < 10)
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
                        if (cabineOccupate[2] < 10)
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
                        if (cabineOccupate[3] < 10)
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

                    if (cabinFull[0] && cabinFull[1] && cabinFull[2] && cabinFull[3] == true)
                    {
                        cabinePiene = true;
                    }
                }
                else
                {
                    printf("Non ci sono cabine libere\n");
                    Sleep(5000);
                    main();
                }

            }
            else if (choice == 1)
            {
                printf("Perfetto, buon viaggio\n");
                Sleep(1000);
                main();
                cont = false;
            }
            else if (choice == 2)
            {
                main();
            }
        }

    } while (cont);
}


void output()
{
    int counter = 0;
    int spesaFamiglia = 0;


    for (int i = 0; i < 4; i++)
    {
        printf(" Cabine da %d occupate : [%d] persone\n", i + 1, cabineOccupate[i]);
    }

    for (int i = 0; i < familyCont; i++)
    {
        printf("\nCabina da %d\n", lungFamiglia[i]);
        for (int j = 0; j < lungFamiglia[i]; j++)
        {
            printf("\nPersona numero %d\n", j + 1);
            printf("Nome: %s\nCognome: %s\n", nomi[j], cognomi[j]);
            printf("Giorno di nascita: %d\nMese di nascita: %d\nAnno di nascita: %d\n", day[j], month[j], year[j]);
            j++;
            printf("");
        }
    }
    Sleep(10000);
    cont = false;
}

float shop()
{
    int choice = 0;
    int personChoice = 0;
    printf("Scegli in quale negozio vuoi andare.\n [0] Bar\n [1] Gucci Store");
    switch (choice)
    {
    case 0:
        personChoice = trovaPersone();
        prezzoFinale[personChoice] += bar();
        break;

    case 1:
        personChoice = trovaPersone();
        prezzoFinale[personChoice] += gucci();
        break;

    default:
        printf("Scelta Sbagliata!\n");
        Sleep(2000);
        clear();
        break;
    }

}

float bar()
{
    int choice = 0;
    float total = 0;
    float cosBar[] = { 6.00f, 6.50f, 20.0f };
    char nomBar[][20] =
    {
        {"Aperol"},
        {"Whiskey"},
        {"Negroamaro"}
    };

}


int trovaPersone()
{
    char name[20] = ""; 
    char surname[20] = ""; 
    int index = 0;
    bool isOn = false;

    do
    {
        printf("Inserisci il suo nome\n");
        scanf("%s", name);
        printf("Inserisci il suo cognome\n");
        scanf("%s", surname);
        for (int i = 0; i < nPersone; i++)
        {
            if (strcmp(name, nomi[i]) == 0 && strcmp(surname, cognomi[i]) == 0)
            {
                index = i;
                isOn = true;
                break;
            }
        }
    } while (!isOn);
    return index;
}


float gucci()
{
    int choice = 0;
    float total = 0;
    float prezzo[] = { 800.00f, 900.00f, 430.00f };
    char nomGucci[][20] =
    {
        {"T-shirt"},
        {"Borsa"},
        {"Scarpe vintage"}
    };
    int carrello[3];
    for (int i = 0; i < 3; i++)
    {
        carrello[i] = 0;
    }
    do
    {
        printf("Cosa desideri acquistare?:\n");
        for (int i = 0; i < 3; i++)
        {
            printf("[%d]%s = %.2f $\n", i, nomGucci[i], prezzo[i]);
        }
        printf("[3] Indietro\n");
        scanf("%d", &choice);
        if (choice < 3)
        {
            carrello[choice]++;
            total += prezzo[choice];
        }
        else if (choice == 3)
        {
            printf("Scontrino:\n");
            for (int i = 0; i < 3; i++)
            {
                if (carrello[i] != 0)
                {
                    printf("%d %s\n", carrello[i], nomGucci[i]);
                }
            }
            printf("Totale: %.2f $\n", total);
            Sleep(1000);
        }
        else
        {
            printf("Inserisci una scelta valida\n");
            Sleep(1000);
            clear();
        }
    } while (choice != 3);
    return total;
}


void clear()
{
    system("cls");
}
