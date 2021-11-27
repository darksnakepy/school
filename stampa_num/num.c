#include <stdlib.h>
#include <stdio.h>

int main()
{
	int x, y, z;
	int num0, num1, num2;
	printf("Inserisci un numero: ");
	scanf("%d", &x);
	printf("Inserisci un numero: ");
	scanf("%d", &y);
	printf("Inserisci un numero: ");
	scanf("%d", &z);

	if (x > y || x > z)
	{
		num2 = x;
		if (y > z)
		{
			num1 = y;
			num0 = z;
		}
		else
		{		
			num1 = z;
			num0 = y;
		}
	}
	else
	{
		num0 = x;
		if (y > z)
		{
			num1 = z;
			num2 = y;
		}
		else 
		{
			num1 = y;
			num2 = z;
		}
	}
	
	printf("Primo Numero %d\n", num0);
	printf("Secondo Numero %d\n", num1);
	printf("Terzo Numero %d\n", num2);

}
