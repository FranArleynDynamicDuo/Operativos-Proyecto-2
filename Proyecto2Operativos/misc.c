#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include "misc.h"

//From stackoverfow (Ryan Reich), modified (Pedro Perez) for this project
int RandomBetween(int min, int max)
{
    static int randompass = 0;
    
    max = max - min;
    
    if(!randompass)
    {
        srand(time(NULL));
        randompass = 1;
    }
    
    unsigned long
    // max <= RAND_MAX < ULONG_MAX, so this is okay.
    num_bins = (unsigned long) max + 1,
    num_rand = (unsigned long) RAND_MAX + 1,
    bin_size = num_rand / num_bins,
    defect   = num_rand % num_bins;
    
    long x;
    do
    {
        x = rand();
    }
    // This is carefully written not to overflow
    while (num_rand - defect <= (unsigned long)x);
    
    // Truncated division is intentional
    return (int)(x/bin_size + min);
}

int IsNumber(char* str)
{
    char* index = str;
    int isNumber = 1;
    while (*index != 0 && isNumber)
    {
        if (!isdigit(*index))
        {
            isNumber = 0;
        }
        index++;
    }
    return isNumber;
}

void Raise(int code)
{
    switch (code)
    {
        case 0:
            printf("Invalid syntax.\n");
            printf("Example: [-d path] <n> <m> <output>\n");
            break;
        case 1:
            printf("Unknown arguments.\n");
            break;
        case 2:
            printf("No such file or directory.\n");
            break;
    }
    exit(code);
}

int InArray(int* a, int index, int n)
{
    int i;
    for (i = 0; i <= index; i++)
    {
        if (a[i] == n) return 1;
    }
    return 0;
}