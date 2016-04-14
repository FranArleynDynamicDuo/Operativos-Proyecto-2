/*
 * @Lista.h
 *
 * @Autores: 
 *			@Arleyn Goncalves 10-10290
 *			@Francisco Sucre  10-10717
 */

#ifndef LISTA_H_
#define LISTA_H_
#include <stdio.h>
#include <stdlib.h>
#include "Pregunta.h"

/* 	@ Estructura que es un puntero para señalar el inicio y el final de la lista.
 *  @ Pregunta *primero: Señala el primer elemento de la lista.
 *  @ Pregunta *ultimo: Señala el ultimo elemento de la lista.
 */

typedef struct lista{

	Pregunta *primero;
	Pregunta *ultimo;

}Lista;


/* 	@Nombre: Leer_BaseDeDatos.
 *  @Funcion: Leer un archivo de entrada txt y las guarda en una lista enlazada
 *  @Entrada: Ingresa un archivo txt.
 *  @Salida: Retorna una lista enlazada con los datos del txt.
 */

Lista *Leer_BaseDeDatos(FILE *files,Lista *baseDatos);


/* @Nombre: Insertar_Pregunta
 * @Funcion: Inserta una pregunta a la lista enlazadas.
 * @Entrada: Ingresa la lista enlazada.
 * @Salida: Retorna una lista enlazada con la nueva pregunta que se posiciona al final de esta.
 */

Lista *Insertar_Pregunta(Lista *baseDatos);


/* @Nombre: Eliminar_Pregunta
 * @Funcion: Eliminar una pregunta segun el codigo señalado por el usuario
 * @Entrada: Ingresa la lista enlazada.
 * @Salida: Retorna la lista enlazada pero esta vez se ha eliminado la pregunta señalada segun el codigo ingresado
 */

Lista *Eliminar_Pregunta(Lista *baseDatos);


/* @Nombre: Consultar_Preguntas
 * @Funcion: Imprime todas las preguntas de la lista.
 * @Entrada: Ingresa la lista enlazadas.
 */

void Consultar_Preguntas(Lista *baseDatos);


/* @Nombre: Consultar_PreguntasNivel
 * @Funcion: Imprime todas las preguntas de la listas, relacionadas por el nivel ingresado por el ususario.
 * @Entrada: Ingresa la lista enlazada.
 */

void Consultar_PreguntasNivel(Lista *baseDatos);

/* @Nombre: Salvar_BaseDeDatos.
 * @Funcion: Salva la lista enlazada guardandolas en un archivo .txt
 * @Entrada: Ingresa la lista
 * @Salida: Retorna un archivo .txt con todas las preguntas de la lista.
 */

void Salvar_BaseDeDatos(FILE *files,Lista *baseDatos);


#endif /* LISTA_H_ */
