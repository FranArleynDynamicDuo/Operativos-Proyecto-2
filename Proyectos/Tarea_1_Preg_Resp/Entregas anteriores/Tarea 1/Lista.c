/*
 * lista.c
 *
 *  Created on: Apr 17, 2015
 *      Author: franciscosucre
 */

#include "Lista.h"
#include "Pregunta.h"
#include <stdio.h>
#include <stdlib.h>


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

void Insertar_Pregunta(Pregunta *primero,Pregunta *ultimo)
{
	Pregunta *nuevo;
	nuevo = (Pregunta *)malloc(sizeof(Pregunta));

	if (nuevo == NULL)
	{
		printf("No hay memoria disponible\n");
	}

	printf("\nNuevo elemento\n");

	int id_num;
	printf("Codigo: "); fflush(stdout);
	scanf("%d",&id_num);
	nuevo->id_num = id_num;

	printf("Categoria: "); fflush(stdout);
	scanf("%s",&nuevo->categoria);

	int nivel;
	printf("nivel: "); fflush(stdout);
	scanf("%d",nuevo->nivel);

	printf("Pregunta: "); fflush(stdout);
	scanf("%s",&nuevo->preg);

	printf("Opcion de Respuesta 1: "); fflush(stdout);
	scanf("%s",&nuevo->resp1);

	printf("Opcion de Respuesta 2: "); fflush(stdout);
	scanf("%s",&nuevo->resp2);

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
			free(nuevo);
			Insertar_Pregunta();
		}
}

/* EliminarEmp
Dado el código de una pregunta, la misma se elimina del conjunto de
preguntas. Si no existe una pregunta con ese código el programa
muestra un error
 */

void Eliminar_Pregunta(Pregunta *primero,Pregunta *ultimo)

{
	Pregunta *aux;
	aux = primero;

	int i = 0;
	int cod;

	printf("\nCodigo de pregunta a Eliminar: "); fflush(stdin);
	scanf("%d", &cod);

	if (aux == NULL)
		{
			printf("La lista esta vacia\n");
			getch();
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
					i = i + 1;

					printf("\n   El elemento se elimino exitosamente");
					getch();
				}
			aux = aux -> siguiente;

		}

	if (i == 0)

		{
			printf("\n   No se encontro el elemento en la lista");
			getch();
		}
}


/* Consultar_Preguntas
A través de esta
opción se muestran todas las preguntas de la base de datos
(incluyendo las que han sido añadidas en la sesión actual) con todos
sus atributos: respuestas y respuesta correcta, área, código y nivel
 de complejidad.
*/

void Leer_BaseDeDatos(char direccion[],Pregunta *primero,Pregunta *ultimo)
{

	FILE *files = fopen(direccion, "r");

	if (files == NULL)
	{
	   perror ("Error al abrir fichero.txt");
	}

	Pregunta *pregNueva;
	int comillas = 0;
	char pieza[1];
	char comilla[1] = {"\""};
	int i = 0;

	pregNueva -> id_num = 1;

	while (pregNueva != NULL)
	{

		pregNueva = (Pregunta *)malloc(sizeof(Pregunta));
		fscanf(files,"%d %d %c",&pregNueva -> id_num,&pregNueva->nivel,
				&pregNueva->categoria);

		while(comillas != 2)
		{
			fscanf(files,"%c",pieza);
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
			if (pieza[0] == comilla[0])

			{comillas = comillas + 1;};
			pregNueva->resp3[i] = pieza[0];
			i = i + 1;
		}

		fscanf(files,"%d",&pregNueva->resp_C);


		printf("Id: %d \n Nivel %d \n Categoria %c \n Pregunta %s \n "
				"Resp1 %s \n Resp2 %s \n Resp3 %s \n RespC %d ",
				pregNueva->id_num,pregNueva->nivel,pregNueva->categoria,
				pregNueva->preg,pregNueva->resp1,pregNueva->resp2,
				pregNueva->resp3,pregNueva->resp_C);

//		if (Basedatos.id_num == NULL)
//		{
//
//			Basedatos = pregNueva;
//
//		}
//
//		else
//		{
//
//			Basedatos = Insertar_Pregunta(Basedatos);
//
//		}

	}

	fclose(files);
}

void Consultar_Preguntas(Pregunta *primero,Pregunta *ultimo)
{
	Pregunta *aux;
	aux = primero;
	;
	printf("\nMostrando la Lista de Pregunta:");
	printf("\n");

	if (aux == NULL)
		{
			printf("\n   La lista esta vacia!!\n" );
			getch();
		}

	while (aux != NULL)
	{
		printf("\n------------------------------------\n");
		printf(" Codigo: %d,\n Categoria: %s,\n Nivel: %d,\n Pregunta: %s,\n Resp 1: %s,\n Resp 2: %s,\n Resp 3: %s,\n Resp Correcta: %d,\n",
                    aux->id_num,aux->categoria,aux->nivel,aux->preg,aux->resp1,aux->resp2,aux->resp3,aux->resp_C);
		aux = aux->siguiente;
		getch();
	}


}

/*
Consultar_PreguntasNivel
Dado un nivel de complejidad se muestran todas las preguntas que
existen actualmente en ese nivel.
*/

void Consultar_PreguntasNivel(Pregunta *primero,Pregunta *ultimo)
{
	Pregunta *aux;
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
			getch();
		}

	while (aux != NULL)
	{
		if (aux->nivel == niv)
		{
			printf("\n------------------------------------\n");
			printf(" Codigo: %d,\n Categoria: %s,\n Nivel: %d,\n Pregunta: %s,\n Resp 1: %s,\n Resp 2: %s,\n Resp 3: %s,\n Resp Correcta: %d,\n",
                    aux->id_num,aux->categoria,aux->nivel,aux->preg,aux->resp1,aux->resp2,aux->resp3,aux->resp_C);
			i++;
			getch();
		}
		aux = aux->siguiente;
	}

	if (i == 0)

		{
			printf("\n   No se encontro el elemento en la lista");
			getch();
		}
}

/*
Consultar_PreguntasNivel
Dado un nivel de complejidad se muestran todas las preguntas que
existen actualmente en ese nivel.
*/

/*Salvar_BaseDeDatos
Cuando se selecciona esta opción se debe salvar en un archivo de
texto toda la información que se tiene en la memoria relacionada con
las preguntas. Un usuario puede salvar varias veces la base de datos
mientras interactúa con el programa
*/

void Salvar_BaseDeDatos(Pregunta *primero,Pregunta *ultimo)
{

}


