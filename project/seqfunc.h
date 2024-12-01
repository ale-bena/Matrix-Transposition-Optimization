#ifndef SEQFUNC_H_
#define SEQFUNC_H_


//SEQUENTIAL CODE

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <string.h>


int isPowerOfTwo(int n); //verifies if the number is a power of 2

float random_float(int min, int max); //generates random float numbers

void initializeMatrix(float** M, int n); //declares the matrix

int checkSym(float** M, int n);

void matTranspose(float** M, float** T, int n);

void printMatrix(float **M, int n);

void freeMemory(float** M, int n);

float** declareMatrix(int n);

void bubbleSort(double sort[], int n);

double timeAverage(double sort[], int n);

void checkCorrectness(float **M, float** T, int n);

double speedup(double timeSeq, double timeAvg);

double efficiency(double speedup, int nthreads);

void cache_flush(void);


#endif

