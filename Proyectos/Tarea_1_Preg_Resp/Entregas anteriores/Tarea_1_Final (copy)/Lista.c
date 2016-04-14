/*
 * lista.c
 *
 *  Created on: Apr 17, 2015
 *      Author: franciscosucre
 */

#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pregunta.h"


/* Insertar_Pregunta
Cuando se selecciona esta opción, se debe mostrar una
interfaz al usuario que le permita insertar una pregunta con todos
sus atributos incluyendo el código. El programa debe también
presentar una opción para que el usuario confirme que ya ha
introducido todos los atributos de una nueva pregunta (esta opción
puede ser una simple pregunta a la que se responda si/no). El usuario
es responsable de introducir todos los atributos de la pregunta
correctamente. El programa no validará que falten atributos o que se
introduzca una pregunta con el mismo código de otra ya existente.
 */

void clean_stdin(void)
{
	int c;
	do
		{
			c=getchar();
		}
		while (c!='\n' && c!=EOF);
}

Lista *Insertar_Pregunta(Lista *baseDatos)
{
	int desicion = 0;
	while (desicion != 1)
	{
		Pregunta *nuevo = (Pregunta *)malloc(sizeof(Pregunta));

		if (nuevo == NULL)
		{
			printf("No hay memoria disponible\n");
			return baseDatos;
		}

		printf("\nNuevo elemento\n");


		printf("Codigo: ");
		clean_stdin();
		scanf("%d",&nuevo->id_num);

		printf("Categoria: ");
		clean_stdin();
		scanf("\n%c",&nuevo->categoria);

		printf("nivel: ");
		clean_stdin();
		scanf("%d",&nuevo->nivel);

		printf("Pregunta (Entre comillas):");
		clean_stdin();
		fgets(nuevo->preg, 100, stdin);

		printf("Opcion de Respuesta 1 (Entre comillas): ");
		fgets( nuevo->resp1, 100, stdin);

		printf("Opcion de Respuesta 2 (Entre comillas): ");
		fgets( nuevo->resp2, 100, stdin );

		printf("Opcion de Respuesta 3 (Entre comillas): ");
		fgets( nuevo->resp3, 100, stdin );

		printf("Respuesta Correcta: ");
		scanf("%d",&nuevo->resp_C);

		printf("\n");
		printf("Se termino de ingresar los datos si = 1/no = 0: ");
		fflush(stdout);
		scanf("%d",&desicion);

		if (desicion == 0)
			{
				printf("Vuelva a ingresar los datos");
			}

		else if (desicion == 1)
			{
				// El campo siguiente es null por ser el ultimo
				nuevo -> siguiente = NULL;

				// Ahora metemos el nuevo elemento en la lista
				// Comprobamos si la lista es vacia

				if (baseDatos->primero == NULL)
					{
						baseDatos->primero = nuevo;
						baseDatos->ultimo = nuevo;
					}
				else
					{
						nuevo->anterior = baseDatos->ultimo;
						(baseDatos->ultimo) -> siguiente = nuevo;
						baseDatos->ultimo = nuevo;
					}

				return baseDatos;
			}
	}
}

/* EliminarEmp
Dado el código de una pregunta, la misma se elimina del conjunto de
preguntas. Si no existe una pregunta con ese código el programa
muestra un error
 */

Lista *Eliminar_Pregunta(Lista *baseDatos)

{
	Pregunta *aux;
	aux = baseDatos->primero;

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
					if (aux == baseDatos->primero)
						{
							if (baseDatos->primero == baseDatos->ultimo)
								{
									baseDatos->primero = NULL;
									baseDatos->ultimo = NULL;
									free(aux);
								}
							else

								{
									baseDatos->primero = baseDatos->primero->siguiente;
									baseDatos->primero->anterior = NULL;
									free(aux);
								}
						}

					else if (aux == baseDatos->ultimo)

						{
							baseDatos->ultimo = aux->anterior;
							baseDatos->ultimo->siguiente = NULL;
							free(aux);
						}

					else
						{
						Pregunta *aux2;

//						aux->anterior->siguiente = aux->siguiente;
//						aux->siguiente->anterior = aux->anterior;
//						free(aux);

						aux2 = aux->anterior;
						aux2->siguiente = aux->siguiente;
						aux2 = aux->siguiente;
						aux2->anterior = aux->anterior;
						free(aux);

						}
					i = i + 1;

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

	return baseDatos;
}




Lista *Leer_BaseDeDatos(FILE *files,Lista *baseDatos)
{

	if (files == NULL)
	{
	   perror ("Error al abrir fichero.txt");
	}

	if (baseDatos->primero != NULL)

	{
		printf("La base de datos debe estar vacia");
		return baseDatos;
	}

	Pregunta *pregNueva;
	int comillas = 0;
	char pieza[1];
	char comilla[1] = {"\""};
	int i = 0;

	while (feof(files) == 0)
	{

		i = 0;
		comillas = 0;
		pregNueva = (Pregunta *)malloc(sizeof(Pregunta));
		fscanf(files,"%d %d %c",&pregNueva -> id_num,&pregNueva->nivel,
				&pregNueva->categoria);
		fflush(stdin);

		while(comillas != 2)
		{
			fscanf(files,"%c",pieza);
			fflush(stdin);
			if (pieza[0] == comilla[0])

			{comillas = comillas + 1;};
			pregNueva->preg[i] = pieza[0];
			i = i + 1;
		}

		i = 0;
		comillas = 0;

		while(comillas != 2)
		{
			fscanf(files,"%c",pieza);
			fflush(stdin);
			if (pieza[0] == comilla[0])

			{comillas = comillas + 1;};
			pregNueva->resp1[i] = pieza[0];
			i = i + 1;
		}

		i = 0;
		comillas = 0;

		while(comillas != 2)
		{
			fscanf(files,"%c",pieza);
			fflush(stdin);
			if (pieza[0] == comilla[0])

			{comillas = comillas + 1;};
			pregNueva->resp2[i] = pieza[0];
			i = i + 1;
		}

		i = 0;
		comillas = 0;

		while(comillas != 2)
		{
			fscanf(files,"%c",pieza);
			fflush(stdin);
			if (pieza[0] == comilla[0])

			{comillas = comillas + 1;};
			pregNueva->resp3[i] = pieza[0];
			i = i + 1;
		}

		fscanf(files,"%d",&pregNueva->resp_C);
		fflush(stdin);

		if ((pregNueva->id_num == 0) && (pregNueva->nivel == 0) &&
				(pregNueva->resp_C == 0))
		{break;}


		printf("Id: %d \nNivel %d \nCategoria %c \nPregunta %s \n"
				"Resp1 %s \nResp2 %s \nResp3 %s \nRespC %d ",
				pregNueva->id_num,pregNueva->nivel,pregNueva->categoria,
				pregNueva->preg,pregNueva->resp1,pregNueva->resp2,
				pregNueva->resp3,pregNueva->resp_C);

		printf("\n");
		printf("\n");

		// El campo siguiente es null por ser el ultimo

		pregNueva -> siguiente = NULL;

		// Ahora metemos el nuevo elemento en la lista
		// Comprobamos si la lista es vacia

		if (baseDatos->primero == NULL)
		{
			baseDatos->primero = pregNueva;
			baseDatos->ultimo = pregNueva;
		}

		else
		{
			pregNueva->anterior = baseDatos->ultimo;
			baseDatos->ultimo->siguiente = pregNueva;
			baseDatos->ultimo = pregNueva;
		}

	}

	return baseDatos;
}

/* Consultar_Preguntas
A través de esta
opción se muestran todas las preguntas de la base de datos
(incluyendo las que han sido añadidas en la sesión actual) con todos
sus atributos: respuestas y respuesta correcta, área, código y nivel
 de complejidad.
*/

void Consultar_Preguntas(Lista *baseDatos)
{
	Pregunta *aux;
	aux = baseDatos->primero;

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
		printf("Codigo: %d\nCategoria: %c\nNivel: %d\nPregunta: "
				"%s\nResp 1: %s\nResp 2: %s\nResp 3: %s\n"
				"Resp Correcta: %d\n",
        aux->id_num,aux->categoria,aux->nivel,aux->preg,aux->resp1,aux->resp2,aux->resp3,aux->resp_C);
		aux = aux->siguiente;
	}

	free(aux);
}

/*
Consultar_PreguntasNivel
Dado un nivel de complejidad se muestran todas las preguntas que
existen actualmente en ese nivel.
*/

void Consultar_PreguntasNivel(Lista *baseDatos)
{
	Pregunta *aux;
	aux = baseDatos->primero;
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



/*Salvar_BaseDeDatos
Cuando se selecciona esta opción se debe salvar en un archivo de
texto toda la información que se tiene en la memoria relacionada con
las preguntas. Un usuario puede salvar varias veces la base de datos
mientras interactúa con el programa
*/

void Salvar_BaseDeDatos(FILE *files,Lista *baseDatos)
{


	if (files == NULL)
	{
	   perror ("Error al abrir fichero.txt");
	}

	Pregunta *aux;
	aux = baseDatos->primero;

	if (aux == NULL)
		{
			printf("\n   La lista esta vacia!!\n" );
			getchar();
			return;
		}

	while (aux != NULL)
	{
		fprintf(files,"%d %d %c %s %s %s %s %d\n",
				aux->id_num,aux->nivel,aux->categoria,
				aux->preg,aux->resp1,aux->resp2,
				aux->resp3,aux->resp_C);

		aux = aux->siguiente;
	}
	printf("\n");
	printf("Su base de datos ha sido guardada\n");
	getchar();

	free(aux);
	return;

}


