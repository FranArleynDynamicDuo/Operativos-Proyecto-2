/*
 * @Pregunta.h
 *
 * @Autores: 
 *			@Arleyn Goncalves 10-10290
 *			@Francisco Sucre  10-10717
 */


#ifndef PREGUNTA_H_
#define PREGUNTA_H_
#include <stdio.h>

 /* @Estructura de listas enlazadas dobles, llamada pregunta que contiene
  *
  * @ id_num: variable de tipo entero, se guarda el codigo de la pregunta.
  * @ categoria: variable de tipo caracter, se guarda la categoria de la pregunta.
  * @ nivel: variable de tipo enterto, se guarda el nivel de la pregunta.Dificultad: 0 = bajo, 1 = intermedio, 2 = alto
  * @ preg: variables de tipo cadena de caracter, se guarda la pregunta
  * @ resp1: variable de tipo cadena de caracter, se guarda la opcion de respuesta numero 1.
  * @ resp2: variable de tipo cadena de caracter, se guarda la opcion de respuesta numero 2.
  * @ resp3: variable de tipo cadena de caracter, se guarda la opcion de respuesta numero 3.
  * @ resp_C: varibale de tipo entero, se guarda la opcion de la respuesta correcta. Puede ser opcion 1,2 y 3
  *
  * @ Tiene dos apuntadores:
  * @ Pregunta *siguiente: apunta a la siguiente caja.
  * @ Pregunta *anterior: apunta a la anterior caja.
  *
  */

typedef struct pregunta

{
	int id_num;
	char categoria;
	int nivel;
	char preg[100];
	char resp1[100];
	char resp2[100];
	char resp3[300];
	int resp_C;
	struct Pregunta *siguiente;
	struct Pregunta *anterior;

} Pregunta;

#endif /* PREGUNTA_H_ */
