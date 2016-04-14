/*
 * Pregunta.h
 *
 *  Created on: Apr 17, 2015
 *      Author: franciscosucre
 */

#ifndef PREGUNTA_H_
#define PREGUNTA_H_

#include <stdio.h>

typedef struct pregunta

{
	//- Un código o identificador de la pregunta.

	int id_num;

	//- El área a la que pertenece la pregunta: Historia (H),
	//  Geografía (G), Tecnología eInformática (T),
	//  Cine (C) y Literatura (L).

	char categoria;

	//- Nivel de complejidad (0=básico, 1= intermedio, 2=avanzado).

	int nivel;


	//- Pregunta

	char preg[100];

	//- Respuestas: Cada pregunta tiene solamente tres posibles
	//  respuestas de las cuales sólo una es la correcta.

	char resp1[100];
	char resp2[100];
	char resp3[300];

	//- Respuesta correcta: Es un entero del 1 al 3 que indica
	//  cuál es la respuesta correcta a la pregunta formulada:
	//  la primera (1), la segunda (2) o la tercera (3).

	int resp_C;

	//- Apuntador a la siguiente pregunta

	struct Pregunta *siguiente;
	struct Pregunta *anterior;

} Pregunta;



#endif /* PREGUNTA_H_ */
