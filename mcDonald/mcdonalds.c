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
int inizio();
int addScorte();

// variabili globali 
int nclienti[maxclienti];
float prezzofinale;
int tempbevande[nbevande];
int temppanini[nPanini]; // scorte panini
int conto[24];
int clienti[maxclienti];
int numClt = 0;

float prezzoPanini[nPanini] = { 6.40, 8.10, 8.60, 8.60, 8.60, 6.70, 2.90, 1.80, 1.30, 4.50, 6.40, 2.90, 1.80, 2.40, 2.90, 1.80, 1.90, 5.60 };
float prezzoBevande[nbevande] = { 1.50, 2.80, 0.55, 2.80, 2.80, 1.90 };

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

char tipibevande[nbevande][maxlength] =
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
    do
    {   
        int choice = 0;
        printf("Benvenuto al McDonald's. Cosa Scegli\n[1]Acquista\n[2]Sezione Staff/Scorte\n");
        scanf_s("%d", &choice);
        switch (choice)
        {
        case 1: comprare();
            break;
        case 2: switch (staffpage())
        {
        case 1: addScorte();
            break;
        case 2: scontrino();
            break;
        case 3: break;
        }
        default: printf("Inserisci un altro numero\n");
            break;
        }
    } while (true);

}

int staffpage()
{
    clear();
    int choice;
    printf("[1]Aggiungi Scorte\n[2]Profitti della giornata\n[3]Torna indietro\n");
    scanf_s("%d", &choice);
    return choice;
}

int addScorte()
{
    clear();
    int scorte = 1;
    int choice = 1;
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

        printf("Quali numeri vuoi aggiungere? [Premere 25 per uscire]\n");
        printf("[24]Scegli il numero di scorte da aggiungere. Default = %d\n", scorte);
        scanf_s("%d", &choice);
        if (choice == 24)
        {
            scorte = addNum();
        }
        else if (choice < 18)
        {
            temppanini[scorte] += scorte;
        }
        else if (choice >= 18)
        {
            tempbevande[scorte - 18] += scorte;
        }

    } while (choice != 25);
}

int addNum()
{
    int num = 1;
    printf("Inserisci quante scorte vuoi aggiungere\n");
    scanf_s("%d", &num);
    return num;
}

int comprare()
{
    clear();
    int choice = 1;

    do
    {
        for (int i = 0; i < nPanini; i++)
        {
            if (temppanini[i] > 0)
            {
                printf("%d  %s\n", i, tipiPanini[i], temppanini[i]);
            }
        }

        for (int i = 0; i < nbevande; i++)
        {
            if (tempbevande[i] > 0)
            {
                printf("%d  %s\n", i + 18, tipibevande[i], tempbevande[i]);
            }
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

int scontrino()
{   
    clear();
    printf("Ecco lo scontrino:\n");
    for (int i = 0; i < nbevande + nPanini; i++)
    {
        if (conto[i] > 0)
        {
            if (i < 18)
            {
                printf("(%d)%s = %.2f $\n", conto[i], temppanini[i], prezzoPanini[i]);
            }
            else if (i >= 18)
            {
                printf("(%d)%s= %.2f $\n", conto[i], temppanini[i - 18], prezzoPanini[i - 18]);
            }
        }
    }
    for (int i = 0; i < nbevande + nPanini; i++)
    {
        if (conto[i] > 0)
        {
            if (i < 18)
            {
                nclienti[maxclienti] += prezzoPanini[i] * conto[i];
            }
            else if (i >= 18)
            {
                nclienti[maxclienti] += prezzoBevande[i - 18] * conto[i];
            }
        }
    }    
}

int clear()
{
    #ifdef _WIN32   
    system("cls");
    #endif
}
