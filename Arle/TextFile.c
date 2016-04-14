/*
 * TextFile.c
 *
 *  Created on: Apr 17, 2015
 *      Author: franciscosucre
 */



#include <stdio.h>
#include "Pregunta.h"
#include "Lista.h"
#include <string.h>

/* Leer_BaseDeDatos
Cuando el usuario elige esta opción el programa lee del archivo de
texto todas las preguntas disponibles junto con sus atributos,
colocando la información en una estructura de datos en memoria. La
idea es que todas las modificaciones que realiza el usuario mientras
interactúa con el programa (durante una sesión) se realicen en la
memoria y sólo se escriban en el archivo al final de la sesión o
cuando el usuario lo especifique a través de la opción Salvar la base
de datos. Si se trata de realizar cualquiera de las operaciones que
se describirán a continuación (consulta, eliminación, etc.) sin haber
leído los datos del archivo, el sistema indicará un error. Por el
contrario, si la operación de Leer la base de datos se invoca más de
una vez dentro de la misma sesión, el programa indicará al usuario
que los datos ya están en la memoria.
 */

Pregunta ReadFile(char direccion[],Pregunta Basedatos)

{

	FILE *files = fopen(direccion, "r");

	if (files == NULL)
	{
	   perror ("Error al abrir fichero.txt");
	}

	Pregunta pregNueva;
	int comillas = 0;
	char pieza[1];
	char comilla[1] = {"\""};
	int i = 0;

	pregNueva.id_num = 1;

	while (pregNueva.id_num != NULL)
	{
		fscanf(files,"%d %d %c",&pregNueva.id_num,&pregNueva.nivel,
				&pregNueva.categoria);

		while(comillas != 2)
		{
			fscanf(files,"%c",pieza);
			if (pieza[0] == comilla[0])

			{comillas = comillas + 1;};
			pregNueva.preg[i] = pieza[0];
			i = i + 1;
		}

		i = 0;
		comillas = 0;

		while(comillas != 2)
		{
			fscanf(files,"%c",pieza);
			if (pieza[0] == comilla[0])

			{comillas = comillas + 1;};
			pregNueva.resp1[i] = pieza[0];
			i = i + 1;
		}

		i = 0;
		comillas = 0;

		while(comillas != 2)
		{
			fscanf(files,"%c",pieza);
			if (pieza[0] == comilla[0])

			{comillas = comillas + 1;};
			pregNueva.resp2[i] = pieza[0];
			i = i + 1;
		}

		i = 0;
		comillas = 0;

		while(comillas != 2)
		{
			fscanf(files,"%c",pieza);
			if (pieza[0] == comilla[0])

			{comillas = comillas + 1;};
			pregNueva.resp3[i] = pieza[0];
			i = i + 1;
		}

		fscanf(files,"%d",&pregNueva.resp_C);


		printf("Id: %d \n Nivel %d \n Categoria %c \n Pregunta %s \n "
				"Resp1 %s \n Resp2 %s \n Resp3 %s \n RespC %d ",
				pregNueva.id_num,pregNueva.nivel,pregNueva.categoria,
				pregNueva.preg,pregNueva.resp1,pregNueva.resp2,
				pregNueva.resp3,pregNueva.resp_C);

		if (Basedatos.id_num == NULL)
		{

			Basedatos = pregNueva;

		}

		else
		{

			Basedatos = Insertar_Pregunta(Basedatos);

		}

	}

	fclose(files);
	return pregNueva;
}

void WriteFile(char direccion[],Pregunta Basedatos)
{

	FILE *files = fopen(direccion, "r");

	if (files == NULL)
	{
	   perror ("Error al abrir fichero.txt");
	}

	while (Basedatos.id_num != NULL)
	{
	   fprintf("%d %d %c %s %s %s %d",
			   &Basedatos.id_num,&Basedatos.nivel,&Basedatos.categoria,
			   Basedatos.preg,Basedatos.resp1,Basedatos.resp2,
			   Basedatos.resp3,&Basedatos.resp_C);
	   Basedatos = *Basedatos.siguiente;
	}

	fclose(files);


}
