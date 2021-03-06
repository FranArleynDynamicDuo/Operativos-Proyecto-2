#include <stdio.h>
#include <stdlib.h>
struct nodo
{
	int id_num;
	char categoria[2];
	int nivel;
	char preg[100];
	char resp1[100];
	char resp2[100];
	char resp3[100];
	int resp_C;
	struct nodo* siguiente;
	struct nodo* anterior;
};

struct nodo *primero, *ultimo; 

void imprimir_menu(void)
 {
 	printf("\n------------------------------------\n");
 	printf("Bienvenido a su base de datos\n");
 	printf("Que desea hacer?\n");
 	printf("\n");
 	printf("1. Leer la base de datos\n");
 	printf("2. Consultar Preguntas\n");
 	printf("3. Consultar Preguntas de un nivel en especifico\n");
 	printf("4. Eliminar una pregunta\n");
 	printf("5. Insertar una pregunta\n");
 	printf("6. Salvar una base de datos\n");
 	printf("7. Salir\n");
 	printf("\n? ");
 }
void Leer_BaseDeDatos()
{

}

void Consultar_Preguntas()
{
	struct nodo *aux;
	aux = primero; 
	;
	printf("\nMostrando la Lista de Pregunta:");
	printf("\n");

	if (aux == NULL)
		{
			printf("\n   La lista esta vacia!!\n" );
			getchar();
		}

	while (aux != NULL)
	{
		printf("\n------------------------------------\n");
		printf(" Codigo: %d,\n Categoria: %s,\n Nivel: %d,\n Pregunta: %s,\n Resp 1: %s,\n Resp 2: %s,\n Resp 3: %s,\n Resp Correcta: %d,\n",
                    aux->id_num,aux->categoria,aux->nivel,aux->preg,aux->resp1,aux->resp2,aux->resp3,aux->resp_C);
		aux = aux->siguiente; 
		getchar();
	}

	
}

void Consultar_PreguntasNivel()
{
	struct nodo *aux;
	aux = primero;
	int niv;
	int i = 0;

	printf("\nNivel a Buscar: "); fflush(stdin);
	scanf("%d", &niv);

	printf("\nMostrando la Lista de Pregunta: ");
	printf("\n");
	
	if (aux == NULL)
		{
			printf( "\n   La lista esta vacia!!\n" );
			getchar();
		}

	while (aux != NULL)
	{
		if (aux->nivel == niv)
		{
			printf("\n------------------------------------\n");
			printf(" Codigo: %d,\n Categoria: %s,\n Nivel: %d,\n Pregunta: %s,\n Resp 1: %s,\n Resp 2: %s,\n Resp 3: %s,\n Resp Correcta: %d,\n",
                    aux->id_num,aux->categoria,aux->nivel,aux->preg,aux->resp1,aux->resp2,aux->resp3,aux->resp_C);
			i++;
			getchar();
		}
		aux = aux->siguiente;
	}

	if (i == 0)

		{
			printf("\n   No se encontro el elemento en la lista");
			getchar();
		}
}

void Eliminar_Pregunta()

{
	struct nodo *aux;
	aux = primero;

	int i = 0;
	int cod;

	printf("\nCodigo de pregunta a Eliminar: "); fflush(stdin);
	scanf("%d", &cod);

	if (aux == NULL)
		{
			printf("La lista esta vacia\n");
			getchar();
		}

	while (aux != NULL)
		{
			if (aux->id_num == cod)
				{
					if (aux == primero)
						{
							if (primero == ultimo)
								{
									primero = NULL;
									ultimo = NULL;
									free(aux);
								}	
							else

								{
									primero = primero->siguiente;
									primero->anterior = NULL;
									free(aux);
								}
						}

					else if (aux == ultimo)
						
						{
							ultimo = aux->anterior;
							ultimo->siguiente = NULL;
							free(aux);
						}

					else
						{
							aux->anterior->siguiente = aux->siguiente;
							aux->siguiente->anterior = aux->anterior;
							free(aux);
						}
					i++;

					printf("\n   El elemento se elimino exitosamente");
					getchar();
				}
			aux = aux -> siguiente;
			
		}

	if (i == 0)

		{
			printf("\n   No se encontro el elemento en la lista");
			getchar();
		}
}

void Insertar_Pregunta()
{
	struct nodo *nuevo;
	nuevo = (struct nodo *)malloc(sizeof(struct nodo));
	
	if (nuevo == NULL)
	{
		printf("No hay memoria disponible\n");
	}
	
	printf("\nNuevo elemento\n");
	
	int id_num;
	printf("Codigo: "); fflush(stdout);
	scanf("%d",&id_num);
	nuevo->id_num = id_num;

	char categoria[2];
	printf("Categoria: "); fflush(stdout);
	scanf("%s",&nuevo->categoria);

	int nivel;
	printf("nivel: "); fflush(stdout);
	scanf("%d",&nivel);
	nuevo->nivel = nivel;

	char preg[100];
	printf("Pregunta: "); fflush(stdout);
	scanf("%s",&nuevo->preg);

	char resp1[100];
	printf("Opcion de Respuesta 1: "); fflush(stdout);
	scanf("%s",&nuevo->resp1);

	char resp2[100];
	printf("Opcion de Respuesta 2: "); fflush(stdout);
	scanf("%s",&nuevo->resp2);

	char resp3[100];
	printf("Opcion de Respuesta 3: "); fflush(stdout);
	scanf("%s",&nuevo->resp3);

	int resp_C;
	printf("Respuesta Correcta: "); fflush(stdout);
	scanf("%d",&resp_C);
	nuevo->resp_C = resp_C;

	int desicion;
	printf("\n");
	printf("Se termino de ingresar los datos si = 1/no = 0: "); fflush(stdout);
	scanf("%d",&desicion);

	if (desicion == 1)
		{
			// El campo siguiente es null por ser el ultimo
			nuevo -> siguiente = NULL;

			// Ahora metemos el nuevo elemento en la lista
			// Comprobamos si la lista es vacia

			if (primero == NULL)
				{
					primero = nuevo;
					ultimo = nuevo;
				}
			else
				{
					nuevo->anterior = ultimo;
					ultimo -> siguiente = nuevo;
					ultimo = nuevo;
				}

		}
	else if (desicion == 0)
		{
			printf("Vuelva a ingresar los datos");
			Insertar_Pregunta();
		}
}

void Salvar_BaseDeDatos()
{
	
}

int main()
{
	int salir = 0;
	int opcion;
	primero = (struct nodo *) NULL;
    ultimo = (struct nodo *) NULL;
	
	while (salir == 0)
		{

			opcion = -1;
			imprimir_menu();
			fflush(stdin);
			scanf("%d", &opcion);

			if (opcion == 1)
			{
				Leer_BaseDeDatos();
			}

			else if (opcion == 2)
			{
				Consultar_Preguntas();
			}

			else if (opcion == 3)
			{
				Consultar_PreguntasNivel();
			}

			else if (opcion == 4)
			{
				Eliminar_Pregunta();
			}

			else if (opcion == 5)
			{
				Insertar_Pregunta();
			}

			else if (opcion == 6)
			{
				Salvar_BaseDeDatos();
			}

			if (opcion == 7)
			{
				salir = 1;
			}

		}
}
