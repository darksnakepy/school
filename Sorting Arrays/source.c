#include <stdio.h>
#include <stdlib.h>
#define nTot 5

int main()
{
	int arr[nTot];
	int temp, j;
	int i;
	for (i = 0; i < nTot; i++)
	{
		printf("Inserisci il numero\n");
		scanf_s("%d", &arr[i]);
	}
	for (i = 0; i < nTot; i++)
	{
		for (j = i + 1; j < nTot; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	printf("Numeri in ordine crescente\n");
	for (i = 0; i < nTot; i++)
	{
		printf("%d\n", arr[i]);
	}
}
