#include <stdio.h>

int doble(int a){

	a = a * 2;
	return a;

}


void main()
{

	int a = 4;
	doble(a);
	printf("\n");
	printf("variable %d ", a );
	printf("\n");
	printf("\n");
}
