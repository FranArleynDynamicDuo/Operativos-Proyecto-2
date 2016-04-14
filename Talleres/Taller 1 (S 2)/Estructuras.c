#include <stdio.h>
#include <stdlib.h>

typedef struct nodo 

	{

	int elem;
	struct nodo *siguiente;

	} nodo;

void main()
{

	int a = 1;
	
	printf("\n");
	printf("---------------------COMIENZO DEL PROGRAMA-----------------------");
	printf("\n");
	printf("\n");
	
	if (a == 5)
		{
		
			int *arreglo = (int*)malloc(4*sizeof(int));
			printf("Arreglooooooooooooooooooooooooooo");
		
		}
		
	else
	
		{
		
			nodo nod;
			nod.elem = 0;
			nod.siguiente = NULL;
			printf("Nodoooooooooooooooooooooooooooooooooooooooooo");
						
		
		}
	
	
	printf("\n");
	printf("\n");
}
