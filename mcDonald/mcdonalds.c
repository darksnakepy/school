#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define nPanini 18 // numero dei tipi di prodotti (panini e patatine/nuggets)
#define nbevande 6 // numero dei tipi di bevande
#define maxlength 100 // secondo indice dell'array di char per la massima lunghezza di ogni carattere
#define tempclienti 1000 // max  clienti 
#define ncoupon 5 // numero dei coupon

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
int profitto();

// variabili globali 
int tempbevande[nbevande];
int temppanini[nPanini];
int conto[24];
float prezzo[tempclienti]; // prezzo che verra' mostrato 
bool couponOn = false;
int nClienti = 0;
float incasso = 0;
int couponChoice[ncoupon];

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

char coupon[ncoupon][maxlength] =
{
    {"DKRTV"},
    {"JCLMD"},
    {"HARNM"},
    {"YFWBD"},
    {"LXHUT"} 
};

int main()
{
    do
    {
        clear();
        int choice = 0;
        printf("\n Benvenuto al McDonald's. Cosa Scegli\n\n [1] - Acquista\n [2] - Sezione Staff/Scorte\n\n>");
        scanf_s("%d", &choice);
        switch (choice)
        {
        case 1: comprare();
            break;
        case 2: switch (staffpage())
        {
        case 1: addScorte();
            break;
        case 2: profitto();
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
    printf("\n [1] - Aggiungi Scorte\n [2] - Incassi della giornata\n [3] - Torna al menu\n\n>");
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
            printf("%d  %s \n", i + 18, tipibevande[i], tempbevande[i]);
        }
        printf("24 Scegli il numero di scorte da aggiungere. Default = %d\n", scorte);
        printf("Quali numeri vuoi aggiungere? [Premere 25 per uscire]\n");
        scanf_s("%d", &choice);
        if (choice == 24)
        {
            scorte = addNum();
        }
        else if (choice < 18)
        {
            temppanini[choice] += scorte;
        }
        else if (choice >= 18)
        {
            tempbevande[choice - 18] += scorte;
        }
    } while (choice != 25);
}

int addNum()
{
    clear();
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
        clear();
        for (int i = 0; i < nPanini; i++)
        {
            if (temppanini[i] > 0)
            {
                printf("[%d] Prodotto = %s || Scorte Disponibili = %d || Prezzo = %.2f $\n", i, tipiPanini[i], temppanini[i], prezzoPanini[i]);
            }
        }

        for (int i = 0; i < nbevande; i++)
        {
            if (tempbevande[i] > 0)
            {
                printf("[%d] Bevanda = %s || Scorte disponibili = %d || Prezzo = %.2f $\n", i + 18, tipibevande[i], tempbevande[i]);
            }
        }
        printf("\nInserisci il numero del prodotto che vuoi acquistare [Premere 24 per stampare lo scontrino]\n>");
        scanf_s("%d", &choice);

        if (choice < 24)
        {
            if (choice < 18 && temppanini[choice] > 0)
            {
                temppanini[choice] -= 1;
                conto[choice] += 1;
            }
            else if (choice >= 18 && tempbevande[choice] > 0)
            {
                tempbevande[choice - 18] -= 1;
                conto[choice] += 1;
            }
            else
            {
                clear();
                printf("L'elemento non e' piu disponibile. Scegline un altro\n");
            }
        }
        else if (choice == 24)
        {
            scontrino();
        }
    } while (choice != 24);
    
    return 0;

}

int scontrino()
{   
    int temp;
    clear();
    printf("Ecco lo scontrino:\n");
    for (int i = 0; i < nPanini + nbevande; i++)
    {
        if (conto[i] > 0)
        {
            if (i < 18)
            {
                printf(" Quantita - [%d] %s = %.2f $\n", conto[i], tipiPanini[i], prezzoPanini[i]);
            }
            else if (i >= 18)
            {
                printf(" Quantita - [%d] %s = %.2f $\n", conto[i], tipibevande[i - 18], prezzoBevande[i - 18]);
            }
        }
    }

    for (int i = 0; i < nPanini + nbevande; i++)
    {
        if (conto[i] > 0)
        {
            if (i < 18)
            {
                prezzo[nClienti] += prezzoPanini[i] * conto[i];
            }
            else if (i >= 18)
            {
                prezzo[nClienti] += prezzoBevande[i - 18] * conto[i];
            }
        }
    }
    sconto();
    if (couponOn == true)
    {
        for (int i = 0; i < ncoupon; i++)
        {
            if (couponChoice[i] > 1)
            {
                prezzo[nClienti] =- 0.25;
            }
        }
    }
    printf("Importo totale da pagare: %2.f $\n", prezzo[nClienti]);
    nClienti += 1;
    system("pause");
}

int sconto()
{   
    char scegliCoupon[maxlength] = { "" };
    printf("Hai la possibilita di inserire un coupon di sconto. Se non ne hai premi 0\n");
    scanf("%s", scegliCoupon);
    for (int i = 0; i < ncoupon; i++)
    {
        if (strcmp(coupon[i], scegliCoupon) == 0)
        {
            printf("Coupon Valido!\n");
            couponChoice[i] += 1;
            couponOn = true;
        }
        else
        {
            couponOn = false;
        }
    }
    return 0;
}

int profitto()
{   
    clear();
    int i = 0;
    while (prezzo[i] > 0)
    {
        incasso += prezzo[i];
        i++;
    }
    printf("Clienti totali: %d\n", i);
    printf("Incasso totale della giornata: %2.f\n $", incasso);
    system("pause");
}
int clear()
{
    #ifdef _WIN32   
    system("cls");
    #endif
}
