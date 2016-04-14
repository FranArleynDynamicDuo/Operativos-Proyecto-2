#ifndef CORE_H
#define	CORE_H

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include "args.h"
#include "misc.h"
#include "list.h"


void MiCuento(Args_t);
void ProcessFiles(char*, int*, int);

#endif