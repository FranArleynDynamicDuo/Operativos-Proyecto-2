#ifndef ARGS_H
#define ARGS_H

typedef struct
{
	char* ruta;
	char* salida;
	int archivos;
	int carpetas;	
} Args;

Args* CrearArgs();
Args* CargarArgs(int, char**);
int Valido(Args*);
int Numero(char*);

#endif
