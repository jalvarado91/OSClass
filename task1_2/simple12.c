/*##########################################################
## COP4610 – Principles of Operating Systems – Summer C 2017
## Prof. Jose F. Osorio
## Student: Juan Alvarado – 3367805
##
## Assignment #: 3
## Specs: Task 1.1 & 1.2, Scheduling Problem
## Due Date: 06/09/2017 by 11:55pm
##
## Module Name: task13
##
## I Certify that this program code has been written by me
## and no part of it has been taken from any sources.
##########################################################*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>

#ifdef PTHREAD_SYNC
	pthread_barrier_t barr;
	pthread_mutex_t mutex;
#endif

int shared_variable = 0;
int nthreads;

void * simple_thread(void *ptr);


int main(int argc, char *argv[])
{
	// Input Validation
	if (argc <= 1)
	{
		printf("Error: Please specify a number of threads as an argument.\n");
		return 0;
	}

	nthreads = atoi(argv[1]);
	if (!nthreads)
	{
		printf("Argument is not a number.\n");
		return 0;
	}
	printf("nthreads %d\n", nthreads);

	long thread_num;
	pthread_t threads[nthreads];
	int threadIds[nthreads];

	#ifdef PTHREAD_SYNC
		pthread_barrier_init(&barr, NULL, nthreads);
		pthread_mutex_init(&mutex, NULL);
	#endif

	for (thread_num = 0; thread_num < nthreads; thread_num++) {
		threadIds[thread_num] = thread_num + 1;
		pthread_create(&threads[thread_num], NULL, simple_thread, (void *)&threadIds[thread_num]);
	}

	for (thread_num = 0; thread_num < nthreads; thread_num++) {
		pthread_join(threads[thread_num], NULL);
	}

	#ifdef PTHREAD_SYNC
		pthread_mutex_destroy(&mutex);
	#endif

	return 0;
}

void * simple_thread(void *param)
{
	int which = *((int *) param);
	int num, val = 0;
	for (num = 0; num < 20; num++)
	{
		if (random() > RAND_MAX / 2)
			usleep(10);
		
		#ifdef PTHREAD_SYNC
			pthread_mutex_lock(&mutex);
		#endif

		val = shared_variable;
		printf("*** thread %d sees value %d\n", which, val);
		shared_variable = val + 1;

		#ifdef PTHREAD_SYNC
			pthread_mutex_unlock(&mutex);
		#endif
	}

	#ifdef PTHREAD_SYNC
		pthread_barrier_wait(&barr);
	#endif

	val = shared_variable;
	printf("Thread %d sees final value %d\n", which, val);
}