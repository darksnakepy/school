#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define nPanini 18
#define nbevande 6
#define maxlength 100
#define maxclienti 100
 


// dichiaro le funzioni
int clear();
int welcome();
int comprare();
int stafflogin();
int staffpage();
int addNum();
int scontrino();

// variabili globali 
int nclienti[maxclienti];
float prezzofinale;
int tempbevande[nbevande];
int temppanini[nPanini];
int conto[24];
char password[maxlength] = "admin";
char input[maxlength];

float prezzoPanini[nPanini] = { 6.40, 8.10, 8.60, 8.60, 8.60, 6.70, 2.90, 1.80, 1.30, 4.50, 6.40, 2.90, 1.80, 2.40, 2.90, 1.80, 1.90, 5.60 };
float prezzoBevande[nbevande] = {1.50, 2.80, 0.55, 2.80, 2.80, 1.90};

char tipiPanini[nPanini][maxlength] =
    {
        {"Big Mac"},
        {"Gran Crispy"},
        {"Chicken Asiago"},
        {"Montasio & DOP"},
        {"BBQ"},
        {"Crispy McBacon"},
        {"Double Cheeseburger"},
        {"Cheeseburger"},
        {"Hamburger"},
        {"Gluten Free Burger"},
        {"McChicken Originale"},
        {"Double Chicken BBQ"},
        {"Chickenburger"},
        {"McMuffin Bacon Egg"},
        {"Filet O Fish"},
        {"McToast"},
        {"Patatine"},
        {"6x Chicken Nuggets"}
    };

char tipibevande[nbevande][maxlength]=
    {
        {"Acqua"},
        {"Coca Cola"},
        {"Pepsi"},
        {"Fanta"},
        {"Sprite"},
        {"Mountain Dew"}
    };


int main()
{
    int choice;
    printf("Benvenuto al McDonald's. Cosa Scegli\n[1]Acquista\n[2] Sezione Staff/Scorte\n");
    scanf("%d", &choice);
    do
    {
        switch (choice)
        {
        case 1: comprare();
            break;
            case 2: switch (staffpage())
                            {
                                case 1: addScorte();
                                        break;
                                case 2: scontrino();
                            }
        }

    } while (true);
}


int stafflogin()
{
 
    printf("Inserisci la password per poter accedere alla schermata di admin");
    scanf("%s", &input);
    if (input != password)
    {
        printf("Accesso vietato.\n");
    }
    else
    {
        printf("Accesso eseguito..\n");
    }
    return stafflogin;
}

int staffpage()
{   
    clear();
    int choice;
    printf("Cosa vuoi fare:\n[1]Aggiungi Scorte\n[2]Profitti della giornata\n[3]Spegnere totem\n");
    scanf("%d", &choice);
    return choice;
}

int comprare()
{
    int choice = 0;

    do
    {
        for (int i = 0; i < nPanini; i++)
        {
            printf("%d  %s %d = %.2f $\n", i, tipiPanini[i], temppanini[i], prezzoPanini[i]);
        }

        for (int i = 0; i < nbevande; i++)
        {
            printf("%d  %s %d = %.2f $\n", i+18, tipibevande[i], tempbevande[i], prezzoBevande[i]);
        }
        printf("Inserisci il numero del prodotto che vuoi acquistare [Premere 24 per terminare]\n");
        scanf_s("%d", &choice);

        if (choice < 24)
        {
            if (choice < 18 && temppanini[choice] > 0)
            {
                temppanini[choice] += 1;
                conto[choice] += 1;
            }
            else if (choice >= 18 && tempbevande[choice] > 0)
            {
                tempbevande[choice - 18] -= 1;
                conto[choice] += 1;
            }
            else
            {
                printf("Scelta Sbagliata! Ritorna al menu' per riordinare\n");
            }
        }

        else if (choice == 24)
        {
            scontrino();
        }
    } while (choice != 24);

}

int addScorte()
{
    int scorte, choice;
    printf("Ecco la lista dei prodotti disponibili\n");
    do {

        for (int i = 0; i < nPanini; i++)
        {
            printf("%d  %s\n", i, tipiPanini[i], temppanini[i]);
        }

        for (int i = 0; i < nbevande; i++)
        {
            printf("%d  %s\n", i + 18, tipibevande[i], tempbevande[i]);
        }

        printf("Quali numeri vuoi aggiungere?\n");
        scanf("%d", &choice);
        if (choice == 24)
        {
            scorte = addNum();
        }
        else if (choice < 0)
        {
            temppanini[choice] += addNum();
        }
        else if (choice > 10)
        {
            tempbevande[choice - 18] += addNum();
        }

    } while (choice != 25);
}

int addNum()
{
    int num = 1;
    printf("Quale panino vuoi aggiungere?\n");
    scanf("%d", &num);
    return num;
}

int scontrino()
{

}

int clear()
{
    #ifdef _WIN32   
    system("cls");
    #endif
}
