#include <stdio.h>
#include <stdlib.h>

int functionOne(const int i)
	{
		printf("Parametro recebido: %d\n", i);
		return i;
	}

int main(int argc, char **argv)
	{
	printf("Valor informado: %s\n", argv[1]);
	int param = atoi(argv[1]);
	int (*function)(int);

	function = &functionOne;
	function(param);
	return 0;
	}
