#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// functions 
void registerUser();
void shop();
void output(); 
void clear(); 
int trovaPersone();
float gucci();
float bar();

// const var
#define maxPersone 100
#define ncabine 10
#define tipiCabine 4
#define maxLght 1000

int numeroFamiglie = 0;
int nPersone = 0; // nPersone registrate
char nomi[maxPersone][maxLght];
char cognomi[maxPersone][maxLght];
int day[maxPersone];
int month[maxPersone];
int year[maxPersone];
int lungFamiglia[maxPersone];
int familyCont = 0; // posizione famiglia

float prezzoFinale[maxPersone];


int cabineOccupate[4]; // cabine occupate
bool cont = true; // contatore
bool registered = false; // persone registrate
bool cabinePiene = false; // cabine piene o no
 


int main()
{
    clear();
    int choice;
    printf("\n Benvenuto nel programma di registrazione di Costa Crociera!\n [0] Registra membri\n [1] Staff\n\n >");
    scanf("%d", &choice);
    do
    {
        switch (choice)
        {
        case 0:
            registerUser();
            break;
        case 1:
            output();
            break;
        default:
            printf("Errore\n");
            break;
        }

    } while (cont);
}

void registerUser()
{
    int choice;
    int family;
    bool cabinFull[4];

    for (int i = 0; i < 4; i++)
    {
        cabinFull[i] = false;
    }
    do
    {
        clear();
        if (nPersone < 100)
        {
            if (cabinePiene == false)
            {
                printf("[0] Registra famiglia o persone\n");
            }
            printf("[1] Viaggia\n");
            printf("[2] Torna indietro\n");
            scanf("%d", &choice);
            if (nPersone < 100 && choice == 0 && cabinePiene == false)
            {
                do
                {
                    printf("Inserisci il numero di utenti che vuoi registrare\n>");
                    scanf("%d", &family);

                } while (family < 0 || family > 4);

                if (cabinePiene == false)
                {
                    for (int i = numeroFamiglie; i < family + numeroFamiglie; i++)
                    {
                        printf("Persona numero [%d], perfavore inserire il nome\n", nPersone);
                        scanf("%s> ", &nomi[i]);
                        printf("Inserire il cognome\n");
                        scanf("%s> ", &cognomi[i]);
                        printf("Persona numero [%d], inserisci la tua data di nascita (Giorno)\n", i);
                        scanf("%d> ", &day[i]);
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
                            scanf("%d> ", &year[i]);
                        }
                        printf("Utente registrato!\n");
                    }

                    switch (family)
                    {
                    case 4:
                        if (cabineOccupate[3] < 10)
                        {
                            cabineOccupate[3]++;
                            lungFamiglia[familyCont] = family;
                            familyCont++;
                            nPersone += family;
                            numeroFamiglie += family;
                            break;
                        }
                        else
                        {
                            cabinFull[3] = true;
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
                            numeroFamiglie += family;
                            break;
                        }
                        else
                        {
                            cabinFull[2] = true;
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
                            numeroFamiglie += family;
                            break;
                        }
                        else
                        {
                            cabinFull[1] = true;
                            printf("Non ci sono abbastanza posti\n");
                        }
                        break;
                    case 1:
                        if (cabineOccupate[0] < 10)
                        {
                            cabineOccupate[0]++;
                            lungFamiglia[familyCont] = family;
                            familyCont++;
                            nPersone += family;
                            numeroFamiglie += family;
                            break;
                        }
                        else
                        {
                            cabinFull[0] = true;
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
                    nPersone -= family;
                    printf("Non ci sono cabine libere\n");
                    Sleep(5000);
                    main();
                }

            }
            else if (choice == 1)
            {
                printf("Perfetto, buon viaggio!\n");
                Sleep(2000);
                shop();
                cont = false;
            }
            else if (choice == 2)
            {
                main();
            }
        }
    } while (cont);
}


void shop()
{
    clear();
    int choice = 0;
    int persona = 0;
    do {
        printf("In quale negozio vorresti acquistare.\n [0] Bar\n [1] Gucci Store\n [2] Scontrino Finale\n >");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            persona = trovaPersone();
            prezzoFinale[persona] += bar();
            break;

        case 1:
            persona = trovaPersone();
            prezzoFinale[persona] += gucci();
            break;
        case 2:
            output();
        default:
            printf("Scelta Sbagliata!\n");
            Sleep(2000);
            main();
            break;
        }
    } while (choice != 3);

    for (int i = 0; i < nPersone; i++)
    {
        prezzoFinale[i] += 159.99f; // prezzo defaul di una cabina
    }
}

float bar()
{
    clear();
    int carrello[3];
    int choice = 0;
    float totale = 0;
    float prezzi[] = { 6.00f, 6.50f, 20.0f };
    char cocktail[][20] =
    {
        {"Aperol"},
        {"Whiskey"},
        {"Negroamaro"}
    };

    for (int i = 0; i < 3; i++)
    {
        carrello[i] = 0;
    }

    do
    {
        printf("Cosa desideri acquistare?:\n");
        for (int i = 0; i < 3; i++)
        {
            printf("[%d] %s = %.2f $\n", i, cocktail[i], prezzi[i]);
        }
        printf("[3] Scontrino\n");
        scanf("%d", &choice);
        if (choice < 3)
        {
            carrello[choice]++;
            totale += prezzi[choice];
        }
        else if (choice == 3)
        {
            printf("Scontrino:\n");
            for (int i = 0; i < 3; i++)
            {
                if (carrello[i] != 0)
                {
                    printf("%d %s\n", carrello[i], cocktail[i]);
                }
            }
            printf("Prezzo totale: %.2f $\n", totale);
            Sleep(1000);
        }
        else
        {
            printf("Inserisci una scelta valida\n");
            Sleep(1000);
            clear();
        }
    } while (choice != 3);
    return totale;
}


int trovaPersone()
{
    char name[20] = ""; //input to check if name exists
    char surname[20] = ""; //input to check if surname exists
    int index = 0;
    bool exists = false;

    do
    {
        printf("Inserisca il suo nome\n");
        scanf("%s", name);
        printf("Inserisca il suo cognome\n");
        scanf("%s", surname);
        for (int i = 0; i < nPersone; i++)
        {
            if (strcmp(name, nomi[i]) == 0 && strcmp(surname, cognomi[i]) == 0)
            {
                index = i;
                exists = true;
                break;
            }
            else
            {
                printf("Non esiste alcun utente registrato con questo nome e cognome\n");
                Sleep(3000);
                main();
            }
        }
    } while (!exists);
    return index;
}


float gucci()
{
    clear();
    int choice = 0;
    float totale = 0;
    float prezzo[] = { 400.00f, 800.00f, 250.00f };
    char nomGucci[][20] =
    {
        {"T-shirt"},
        {"Borsa"},
        {"Occhiali"}
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
            totale += prezzo[choice];
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
            printf("Totale: %.2f $\n", totale);
            Sleep(1000);
        }
        else
        {
            printf("Inserisci una scelta valida\n");
            Sleep(1000);
            clear();
        }
    } while (choice != 3);
    return totale;
}


void output()
{
    int counter = 0; 
    float familySpent = 0.0f;
    clear();
    printf("Cabine Occupate\n");
    for (int i = 0; i < 4; i++)
    {
        printf("Cabine da %d occupate : %d\n", i + 1, cabineOccupate[i]);
    }
    for (int i = 0; i < familyCont; i++)
    {
        printf("\nCabina da %d\n", lungFamiglia[i]);
        for (int j = 0; j < lungFamiglia[i]; j++)
        {
            printf("\nPersona numero %d\n", counter + 1);
            printf("Nome: %s\nCognome: %s\n", nomi[counter], cognomi[counter]);
            printf("Giorno di nascita: %d\nMese di nascita: %d\nAnno di nascita: %d\n", day[counter], month[counter], year[counter]);
            printf("Soldi spesi dal singolo: %.2f\n", prezzoFinale[counter]);
            familySpent += prezzoFinale[counter];
            counter++;
        }
        printf("\nSoldi spesi dalla famiglia: %.2f\n", familySpent);
        familySpent = 0.0f;
    }
    cont = false;
}


void clear()
{
    system("cls");
}
