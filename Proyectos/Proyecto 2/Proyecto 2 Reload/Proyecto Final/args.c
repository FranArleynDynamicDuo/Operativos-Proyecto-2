#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "args.h"

// Estructura que almacena los argumentos

Args* CrearArgs()
{
	Args* args = malloc(sizeof(Args));
	args->ruta = NULL;
	args->salida = NULL;
	args->carpetas = 0;
	args->archivos = 0;
	return args;
}

// Funcion que captura los argumentos

Args* CargarArgs(int argc, char** argv)
{
	Args* args = CrearArgs();
	
	int i;
	for (i = 1; i < argc; i++)
	{
		if (argv[i][0] == '-')
		{
			int len = strlen(&argv[i][1]);
			if (argv[i][1] == 'd')
			{
				if (++i < argc)
				{
					args->ruta = argv[i];
				}
				else
				{
					printf("La Sintaxis es Inválida.\n");
            				printf("Ejemplo: [-d path] <n> <m> <output>\n");
					exit(0);
				}
			}
			else
			{
				printf("Argumentos Desconocidos.\n");
				exit(0);
			}
			

		}
		else if (Numero(argv[i]))
		{
			args->carpetas = atoi(argv[i++]);
			args->archivos = atoi(argv[i++]);
			args->salida = argv[i++];	
		}
	}
	
	if (Valido(args))
	{
		return args;
	}
	printf("La Sintaxis es Inválida.\n");
        printf("Ejemplo: [-d path] <n> <m> <output>\n");
	exit(0);
}

// Funcion que determina la validez de los argumentos

int Valido(Args* args)
{
	int valid = 1;
	valid = valid && args->carpetas != 0;
	valid = valid && args->archivos != 0;
	valid = valid && args->salida != NULL;
	return valid;
}

// Funcion que determina si un string es un numero

int Numero(char* str)
{
    char* indice = str;
    int numero = 1;
    while (*indice != 0 && numero)
    {
        if (!isdigit(*indice))
        {
            numero = 0;
        }
        indice++;
    }
    return numero;
}
