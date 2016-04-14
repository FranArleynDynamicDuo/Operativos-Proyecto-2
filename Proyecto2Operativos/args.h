#ifndef ARGS_H
#define ARGS_H

struct args
{
	char* path;
	int folders;
	int files;
	char* output;
};

typedef struct args Args;
typedef Args* Args_t;

Args_t NewArgs();
Args_t ProcessArgs(int, char**);
int IsValid(Args_t);

#endif