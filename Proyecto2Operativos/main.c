#include "core.h"

int main(int argc, char* argv[])
{
	// Arguments processing
	Args_t args = ProcessArgs(argc, argv);
	
	
	// Program excecution
	MiCuento(args);	
	
	return 0;
}