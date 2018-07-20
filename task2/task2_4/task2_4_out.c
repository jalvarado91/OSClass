/*##########################################################
## COP4610 – Principles of Operating Systems – Summer C 2017
## Prof. Jose F. Osorio
## Student: Juan Alvarado – 3367805
##
## Assignment #: 3
## Specs: Task 2.4 Out Both, OpenMP Progam
## Due Date: 06/09/2017 by 11:55pm
##
## Module Name: task2_4_out
##
## I Certify that this program code has been written by me
## and no part of it has been taken from any sources.
##########################################################*/

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define M 50
#define N 50

int num_threads;

int main(int argc, char *argv[])
{
    // Input Validation
	if (argc <= 1)
	{
		printf("Error: Please specify a number threads.\n");
		return 0;
	}

	num_threads = atoi(argv[1]);
	if (!num_threads)
	{
		printf("Arguments are not valid.\n");
		return 0;
	}
    //set number of threads here
    omp_set_num_threads(num_threads);

    int i, j, k;
    double sum;
    double **A, **B, **C;

    A = malloc(M * sizeof(double *));
    B = malloc(M * sizeof(double *));
    C = malloc(M * sizeof(double *));

    for (i = 0; i < M; i++)
    {
        A[i] = malloc(N * sizeof(double));
        B[i] = malloc(N * sizeof(double));
        C[i] = malloc(N * sizeof(double));
    }

    double start, end;

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            A[i][j] = j * 1;
            B[i][j] = i * j + 2;
            C[i][j] = j - i * 2;
        }
    }

    start = omp_get_wtime();

    #pragma omp parallel shared(A,B,C) private(i,j,k)
    {
        #pragma omp for
        for (i = 0; i < M; i++)
        {
            for (j = 0; j < N; j++)
            {
                sum = 0;
                for (k = 0; k < M; k++)
                {
                    sum += A[i][k] * B[k][j];
                }
                C[i][j] = sum;
            }
        }
    }

    end = omp_get_wtime();

    printf("Time of computation: %f\n", end - start);
}
