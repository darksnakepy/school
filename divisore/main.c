#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main()
{
	int n, divisore, numDiv;
	bool cont = true;

	printf("Scrivi un numero maggiore di 0\n");
	scanf("%d", &n);

	if (n > 0)
	{
		divisore = n;
		while (divisore > 0)
		{
			numDiv = n % divisore;
			if (numDiv == 0)
			{
				printf("%d\n", divisore);
			}
			divisore = divisore - 1;
		}

		while (cont == true)
		{
			printf("Scrivi un numero maggiore di 0\n");
			scanf("%d", &n);

			numDiv = n;
			if (n > 0)
			{
				printf("%d\n", numDiv);
			}
			else
			{
			cont == false;
			}
		}
	}
	else
	{
		cont == false;
	}
	system("pause");

}
