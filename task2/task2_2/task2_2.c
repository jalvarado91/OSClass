/*##########################################################
## COP4610 – Principles of Operating Systems – Summer C 2017
## Prof. Jose F. Osorio
## Student: Juan Alvarado – 3367805
##
## Assignment #: 3
## Specs: Task 2.2, OpenMP Program
## Due Date: 06/09/2017 by 11:55pm
##
## Module Name: task2_2
##
## I Certify that this program code has been written by me
## and no part of it has been taken from any sources.
##########################################################*/

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define CHUNKSIZE 10
#define N 100

int main(int argc, char *argv[])
{
	int nthreads, tid, i, chunk;
	float a[N], b[N], c[N];
	double start_time, end_time, elapsed_time;

	for (i = 0; i < N; i++)
		a[i] = b[i] = i * 1.0; // initialize arrays

	chunk = CHUNKSIZE;

	printf("Program starting.\n");
	start_time = omp_get_wtime();
	printf("Start time: %d.\n", start_time);


	#pragma omp parallel shared(a, b, c, nthreads, chunk) private(i, tid) 
	{
		tid = omp_get_thread_num();

		if (tid == 0)
		{
			nthreads = omp_get_num_threads();
			printf("Number of threads = %d\n", nthreads);
		}

		printf("Thread %d starting...\n", tid);

		#pragma omp for schedule(static, chunk)
		for (i = 0; i < N; i++)
		{
			c[i] = a[i] + b[i];
			printf("Thread %d: c[%d]= %f\n", tid, i, c[i]);
		}

	} /* end of parallel section */

	end_time = omp_get_wtime();
	printf("End time: %d. \n", end_time);
	elapsed_time = end_time - start_time;
	printf("Total elapsed time: %d.\n", elapsed_time);
}
