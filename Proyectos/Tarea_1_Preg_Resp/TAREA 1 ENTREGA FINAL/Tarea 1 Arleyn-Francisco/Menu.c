/*
 * Menu Preguntas.c
 * @Autores: 
 *			@Arleyn Goncalves 10-10290
 *			@Francisco Sucre  10-10717
 */

#include <stdio.h>
#include "Lista.h"

/* @ Se imprime el Menu de opciones que puede elegir el usuario con una interfaz clara y facil de usar */

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
 	printf("\nMarque la opcion deseada: ");
 }


