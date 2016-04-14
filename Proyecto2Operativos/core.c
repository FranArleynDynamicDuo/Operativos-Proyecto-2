#include "core.h"

void MiCuento(Args_t args)
{
	int* folders = malloc(sizeof(int)*args->folders);
	int* files = malloc(sizeof(int)*args->files);
	
	pid_t* children = malloc(sizeof(pid_t)*args->folders);
	int* pipes = malloc(sizeof(int)*2*args->folders);
	
	char fNameBuffer[16];
	
	// Random values load
	// FIX THIS!!!!!
	int i, j;
	int randInt;
	for (i = 0; i < args->folders; i++)
	{
		while (InArray(folders, i, randInt = RandomBetween(1, args->folders)));
		folders[i] = randInt;
	}


	// Process execution and pipe creation
	for (i = 0; i < args->folders; i++)
	{
		pipe(&pipes[i * 2]);
	}
	
	for ( i = 0; i < args->folders; i++)
	{
		children[i] = fork();
		
		if (children[i] == 0)
		{
			sprintf(fNameBuffer, "%d", folders[i]);
			printf("%s", fNameBuffer);
			ProcessFiles(fNameBuffer, pipes + i * 2, args->files);
		}
		else
		{
			close(pipes[i * 2 + 1]);
		}
	}
	
	for (i = 0; i < args->folders; i++)
	{
		wait();
	}
	
	char c;
	FILE* out = fopen(args->output, "w");
	for (i = 0; i < args->folders; i++)
	{
		c = 1;
		while (c)
		{
			read(pipes[i * 2], &c, 1);
			fprintf(stdout, "%c", c);
		}
		fprintf(stdout, "\n", c);
	}
}

void ProcessFiles(char* path, int* p, int toRead)
{
	srand(getpid());
	close(p[0]);
	
	
	int* files = malloc(sizeof(int) * toRead);
	
	DIR* dir = opendir(path);
	if (!dir)
	{
		Raise(2);
	}
	
	struct dirent* dp;
	List_t l = NewList();
	while (dp = readdir(dir))
	{
		if (dp->d_type == DT_REG)
		{
			InsertNode(l, dp);
		}
	}	
	
	int i, randInt, size;
	for	(i = 0; i < toRead && l->size &&  i < l->size; i++)
	{	
		while(InArray(files, i, randInt = RandomBetween(1, l->size)));
		files[i] = randInt;
	}
	
	for	(i = 0; i < l->size; i++)
	{
		dp = GetData(l, files[i] - 1);
		char* filePath = malloc(strlen(path) + strlen(dp->d_name) + 2);	
		sprintf(filePath,"%s%c%s", path, '/', dp->d_name);
		
		FILE* fIn = fopen(filePath, "r");
		char c;
		while ((c = fgetc(fIn)) != EOF)
		{
			write(p[1], &c, 1);
		}
		c = 0;
		write(p[1], &c, 1);
		fclose(fIn);
	}
	
	closedir(dir);
	
	
	exit(0);
}