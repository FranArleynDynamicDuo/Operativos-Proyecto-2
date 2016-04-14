#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "args.h"
#include "misc.h"

Args_t NewArgs()
{
	Args_t args = malloc(sizeof(Args));
	args->path = NULL;
	args->folders = 0;
	args->files = 0;
	args->output = NULL;
	return args;
}

Args_t ProcessArgs(int argc, char** argv)
{
	Args_t args = NewArgs();
	
	int i;
	for (i = 1; i < argc; i++)
	{
		if (argv[i][0] == '-')
		{
			int len = strlen(&argv[i][1]);
			if (len > 1 || len == 0)
			{
				printf("Parámetro Desconocido : %s\n", &argv[i][1]);
				exit(0);
			}
			switch (argv[i][1])
			{
				case 'd':
					if (++i < argc)
					{
						args->path = argv[i];
					}
					else
					{
						Raise(0);
					}
					break;
				default:
					Raise(1);
			}
		}
		else if (IsNumber(argv[i]))
		{
			if (!args->folders)
			{
				args->folders = atoi(argv[i]);
			}
			else if (!args->files)
			{
				args->files = atoi(argv[i]);
			}
			else if (!args->output)
			{
				args->output = argv[i];
			}
		}
		else if (!args->output)
		{
			args->output = argv[i];
		}
	}
	
	if (IsValid(args))
	{
		return args;
	}
	Raise(0);
}


int IsValid(Args_t args)
{
	int valid = 1;
	valid = valid && args->folders != 0;
	valid = valid && args->files != 0;
	valid = valid && args->output != NULL;
	return valid;
}