/*
 * Main.c
 *
 *  Created on: Apr 17, 2015
 *      Author: franciscosucre
 */


#include <stdio.h>
#include "Lista.h"
#include "Menu.h"
#include "Pregunta.h"

int main(int argc,char *argv[])

{
	int salir = 0;
	int opcion;
	Lista *baseDatos = (Lista *)malloc(sizeof(Lista));
	baseDatos -> primero = NULL;
	baseDatos-> ultimo = NULL;


	while (salir == 0)
	{

		opcion = -1;
		imprimir_menu();
		fflush(stdin);
		scanf("%d", &opcion);

		switch ( opcion )

		{
		case 1:
			Leer_BaseDeDatos(*argv,baseDatos);
			break;

		case 2:
			Consultar_Preguntas(baseDatos);
			break;

		case 3:
		
			Consultar_PreguntasNivel(baseDatos);
			break;

		case 4:
			Eliminar_Pregunta(baseDatos);
			break;

		case 5:
			Insertar_Pregunta(baseDatos);
			break;

		case 6:
			Salvar_BaseDeDatos(*argv,baseDatos);
			break;

		case 7:
			printf("Gracias por usar nuestro programa!");
			return 1;
		}
	}
	return 1;
}
