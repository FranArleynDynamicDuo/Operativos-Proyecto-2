#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include "args.h"
#include "cuento.h"

// Funcion principal

int main(int argc, char* argv[])
{
	Args* args = CargarArgs(argc, argv);
	
	int carpetas[10];
	int archivos[20];
	int pipes[20];
	char Nombre[16];
	
	pid_t hijos[10];

	int i, j;

	for (i = 0; i < args->carpetas; i++)
	{
		carpetas[i] = i+1;
	}

	for (i = 0; i < args->carpetas; i++)
	{
		pipe(&pipes[i * 2]);
	}
	
	for ( i = 0; i < args->carpetas; i++)
	{
		hijos[i] = fork();
		
		if (hijos[i] == 0)
		{
			sprintf(Nombre, "%d", carpetas[i]);
			Obtenerarchivos(Nombre, &pipes[i*2], args->archivos);
		}
		else
		{
			close(pipes[i * 2 + 1]);
		}
	}

	int respuesta[10];	
	for (i = 0; i < args->carpetas; i++)
	{
		wait(&respuesta[i]);
	}
	
	char c;
	FILE* out = fopen(args->salida, "w");

	for (i = 0; i < args->carpetas; i++)
	{
		while (read(pipes[i * 2], &c, 1) != 0)
		{
			fprintf(out, "%c", c);
		}
	}
	
	return 0;
}

// Funcion que lee los archivos de los directorios especificados por el padre
// y devuelve la cantidad de archivos leidos

void Obtenerarchivos(char* ruta, int* p, int toRead)
{
	close(p[0]);
	DIR* dir;
	if (!(dir = opendir(ruta)))
	{
		printf("No se encuentra el archivo.\n");
		exit(0);
	}	

	int archivos[20];
	int i = 0;
	
	struct dirent* dp;
	
	while ((dp = readdir(dir)) && i < toRead)
	{
		if (dp->d_type == DT_REG)
		{	
			archivos[i] = atoi(dp->d_name);
			i++;
		}
	}

	char rutaArchivo[16];
	char nombreArchivo[16];
	
	for	(i = 0; i < toRead; i++)
	{	
		strcpy(rutaArchivo,ruta);
		strcat(rutaArchivo,"/");
		sprintf(nombreArchivo,"%d",archivos[i]);
		strcat(rutaArchivo,nombreArchivo);


		FILE* fIn = fopen(rutaArchivo, "r");
		if (!fIn)
		{
			break;
		}
		char c;
		while ((c = fgetc(fIn)) != EOF)
		{
			write(p[1], &c, 1);
		}
		c = '\n';
		write(p[1], &c, 1);
		fclose(fIn);
	}
	
	closedir(dir);	
	exit(i+1);
}
