#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


void *workerThreadFunc(void* tid)
{
	long int *myID = (long *) tid;
	printf("Hello world! This is thread %ld\n",*myID);
}

int main()
{
	pthread_t tid0,tid1,tid2;
	pthread_t * pthread[] = {&tid0,&tid1,&tid2};

	for(int i=0; i<3; i++)
	{
		pthread_create(pthread[i],NULL,workerThreadFunc,(void *) pthread[i]);	
	}



	pthread_exit(NULL);
	return 0;
}