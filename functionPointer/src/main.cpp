#include <stdio.h>
#include <stdlib.h>

typedef int (*function)(const int);

int functionOne(const int i)
	{
		printf("Parametro recebido: %d\n", i);
		return i;
	}

/*
int main(int argc, char **argv)
	{
	printf("Valor informado: %s\n", argv[1]);
	int param = atoi(argv[1]);
	int (*function)(int);

	function = &functionOne;
	function(param);
	return 0;
	}
*/


int main(int argc, char **argv)
	{
	function oFunction = functionOne;
	oFunction(5);
	return 0;
	}