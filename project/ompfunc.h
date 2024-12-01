#ifndef OMPFUNC_H_
#define OMPFUNC_H_

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <string.h>


int isPowerOfTwo(int n); //verifies if the number is a power of 2

float random_float(int min, int max); //generates random float numbers

float** declareMatrix(int n); //declares the matrix

void initializeMatrix(float** M, int n); //initializes the matrix with random numbers

int checkSymOMP(float** M, int n); //checks if the matrix is symmetric

void matTransposeOMP(float** M, float** T, int n); //transposes the matrix

void printMatrix(float **M, int n); //prints the matrix, to see if the program works

void freeMemory(float** M, int n); //frees the allocated memory

void bubbleSort(double sort[], int n);

double timeAverage(double sort[], int n);

void checkCorrectness(float **M, float** T, int n);

double speedup(double timeSeq, double timeAvg);

double efficiency(double speedup, int nthreads);

void cache_flush(void);


#endif
