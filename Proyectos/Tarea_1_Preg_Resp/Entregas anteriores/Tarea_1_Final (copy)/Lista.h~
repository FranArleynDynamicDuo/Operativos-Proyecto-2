/*
 * Lista.h
 *
 *  Created on: Apr 17, 2015
 *      Author: franciscosucre
 */

#ifndef LISTA_H_
#define LISTA_H_

#include <stdio.h>
#include <stdlib.h>
#include "Pregunta.h"

typedef struct lista{

	Pregunta *primero;
	Pregunta *ultimo;

}Lista;

Lista *Leer_BaseDeDatos(FILE *files,Lista *baseDatos);

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

Lista *Insertar_Pregunta(Lista *baseDatos);

/* EliminarEmp
Dado el código de una pregunta, la misma se elimina del conjunto de
preguntas. Si no existe una pregunta con ese código el programa
muestra un error
 */

Lista *Eliminar_Pregunta(Lista *baseDatos);

/* Consultar_Preguntas
A través de esta
opción se muestran todas las preguntas de la base de datos
(incluyendo las que han sido añadidas en la sesión actual) con todos
sus atributos: respuestas y respuesta correcta, área, código y nivel
 de complejidad.
*/



void Consultar_Preguntas(Lista *baseDatos);

/*
Consultar_PreguntasNivel
Dado un nivel de complejidad se muestran todas las preguntas que
existen actualmente en ese nivel.
*/

void Consultar_PreguntasNivel(Lista *baseDatos);

/*Salvar_BaseDeDatos
Cuando se selecciona esta opción se debe salvar en un archivo de
texto toda la información que se tiene en la memoria relacionada con
las preguntas. Un usuario puede salvar varias veces la base de datos
mientras interactúa con el programa
*/

void Salvar_BaseDeDatos(FILE *files,Lista *baseDatos);


#endif /* LISTA_H_ */
