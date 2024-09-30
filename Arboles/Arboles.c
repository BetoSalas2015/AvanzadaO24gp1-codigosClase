#include "Arboles.h"
#include <stdlib.h>			//  para usar rand() y srand()
#include <time.h>

#define SIZE 15
#define MAXRAND 2000

void imprimeArreglo( int arreglo[] )
{
	int i;
	for(i = 0; i < SIZE; ++i)
		printf("%d, ", arreglo[i]);
	putchar('\n');
}

void insert(int arr[], int size)
{
	int y, i, k;
	for(k = 0; k < size; k++)
	{
		y = arr[k];
		for(i = k - 1;(i >= 0 && y < arr[i]); i--)
			arr[i + 1] = arr[i];
		arr[i + 1] = y;
	}
}

nodo *insert_sub(int arr[], int linf, int lsup)
{
	
}

int main()
{
	int arreglo[SIZE];
	int i;
	
	srand( time(0) );
	
	for(i = 0; i < SIZE; ++i)
		arreglo[i] = rand() % MAXRAND;
	
	imprimeArreglo(arreglo);
	
	insert(arreglo, SIZE);
	
	imprimeArreglo(arreglo);
	
	return 0;
}











