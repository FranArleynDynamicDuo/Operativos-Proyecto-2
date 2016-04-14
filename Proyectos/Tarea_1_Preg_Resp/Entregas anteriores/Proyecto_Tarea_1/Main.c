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

int main(char *argv[])

{
	int salir = 0;
	int opcion;
	Pregunta *primero = NULL;
	Pregunta *ultimo = NULL;


	while (salir == 0)
	{

		opcion = -1;
		imprimir_menu();
		fflush(stdin);
		scanf("%d", &opcion);

		switch ( opcion )

		{
		case 1:
			Leer_BaseDeDatos(*argv,primero,ultimo);
			break;

		case 2:
			Consultar_Preguntas(primero,ultimo);
			break;

		case 3:
		
			Consultar_PreguntasNivel(primero,ultimo);
			break;

		case 4:
			Eliminar_Pregunta(primero,ultimo);
			break;

		case 5:
			Insertar_Pregunta(primero,ultimo);
			break;

		case 6:
			Salvar_BaseDeDatos(*argv,primero,ultimo);
			break;

		case 7:
			printf("Gracias por usar nuestro programa!");
			return 1;
		}
	}
}
