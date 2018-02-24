#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void * thread_sum(void * llArg)
	{
	long long limit = *(long long *)llArg;
	printf("thread_sum arg: %lld\n", limit);

	//return of the thread
	pthread_exit(NULL);
	}


int main(int argc, char **argv)
	{
	if (argc < 2)
		{
		printf("Usage: %s <num> \n", argv[0]);
		exit(-1);
		}

	long long limit = atoll(argv[1]);

	printf("Argumento: %d\n", argc);
	printf("Argumento: %lld\n", limit);

	//Create thread id
	pthread_t tId;
	//Create thread attributes
	pthread_attr_t attr;
	//Initialize thread
	pthread_attr_init(&attr);
	//Create and join thread
	pthread_create(&tId, &attr, thread_sum, &limit);
	pthread_join(tId, NULL);

	return 0;
	}
