#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define NUM 5

int main()
{
	int choice;
	int arr[NUM];

	printf("\n [1] Bubble Sort\n [2] Sorting Arrays\n [3] Trova l'elemento piu grande o piu piccolo in una lista di array\n [4] Trova array duplicati\n\n>");
	scanf("%d", &choice);
	do {
		switch (choice)
		{
		case 1:
			writeNumbers(arr);
			bubbleSort(arr);
			break;

		case 2:
			writeNumbers(arr);
			sortingArrays(arr);
			break;

		case 3:
			writeNumbers(arr);
			grandePiccolo(arr);
			break;

		case 4:
			writeNumbers(arr);
			duplicatedArray(arr);
			break;
		}
	} while (true);
}


int writeNumbers(int arr[])
{
	for (int i = 0; i < NUM; i++)
	{
		printf("\n Inserisci un numero:\n\n>");
		scanf("%d", &arr[i]);
	}
} 

int bubbleSort(int arr[]) 
{
	int temp;
	for (int i = 0; i < NUM; i++)
	{
		for (int j = i + 1; j < NUM; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (int i = 0; i < NUM; i++)
	{
		printf("%d ", arr[i]); // stampa gli array in ordine crescente con il metodo BUBBLE SORT
	}
	return 0;
}

int sortingArrays(int arr[]) 
{
	int temp, j;
	for (int i = 0; i < NUM; i++)
	{
		int min = i;
		for (j = i + 1; j < NUM; j++)
		{
			if (arr[j] < arr[min])
				min = j;
		}
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	for (int i = 0; i < NUM; i++)
	{
		printf("%d \n", arr[i]); // stampa gli array in ordine crescente con il metodo "sorting"
	}
	return 0;
}

int grandePiccolo(int arr[])
{
	int max = arr[0];
	for (int i = 0; i < NUM; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	int min = arr[0];
	for (int i = 0; i < NUM; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	printf("\n Il numero piu grande nella lista e' %d \n", max);
	printf("\n Il numero piu piccolo nella lista e' %d \n", min);
	return 0;
}

int duplicatedArray(int arr[])
{
	int i, j, cont = 0;
	for (i = 0; i < NUM; i++)
	{
		for (j = i + 1; j < NUM; j++)
		{
			if (arr[i] == arr[j])
			{
				cont++;
			}
		}
	}
	printf("\n Sono stati trovati %d duplicati", cont);
	return 0;
}

