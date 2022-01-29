#include <stdio.h>
#include <stdlib.h>
#define nprodotti 18
#define maxlength 100

int main()
{	
	void clear();
	void welcome();
	int choice, i;
	char prodotti[nprodotti][maxlength] = 
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
        {"Chicken Nuggets"}
    };
	welcome();

	printf("Scelta:\n[1] Prodotti\n[2] Bevande\n[3] Scontrino\n[4] Coupon Utilizzabili\n");
	scanf("%d", &choice);
	clear();
	for (i = 0; i < nprodotti; i++)
	{	
		printf("%s\n", prodotti[i]);
	}
}









void welcome()
{
	printf("Welcome to McDonald's\nRemember that if you want to use a coupon, you can insert the code in the section [4] Coupons\n");
	printf("");
}

void clear()
{
	#ifdef _WIN32   
    system("cls");
    #endif
}
