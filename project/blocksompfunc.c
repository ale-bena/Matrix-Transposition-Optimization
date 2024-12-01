#include "blocksompfunc.h"
#define min(a, b) ((a) < (b) ? (a) : (b))
int isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0); //usese the binary 
}

float random_float(int min, int max){
	float n;
	int tmp=0;
	tmp = rand() % ((max-min+1)+min);
	n=(float)tmp/100;
	return n;
}

float** declareMatrix(int n){
	float** M = (float**)malloc(n * sizeof(float*));
	if(M==NULL){
		exit(1);
	}
	for (int i = 0; i < n; ++i) {
        	M[i] = (float*)malloc(n * sizeof(float));
        	if(M[i]==NULL){
        		free(M);
        		exit(1);
        	}
    	}
    	return M;
}

void initializeMatrix(float** M, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            M[i][j] = random_float(0,9999);
        }
    }
}


int checkSymOMP(float** M, int n) {
    int tmp = 1;
#pragma omp parallel for reduction(&&:tmp)
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (M[i][j] != M[j][i]) {
                tmp = 0; 
            }
        }
    }
    return tmp;
}



void matTransposeOMP(float** M, float** T, int n, int blockSize) {
    if(checkSymOMP(M,n)==0){
#pragma omp parallel for collapse(2) shared(M, T)
    for (int i = 0; i < n; i += blockSize) {
        for (int j = 0; j < n; j += blockSize) {
            int check=min(n, (i+blockSize));
            int check2=min(n, (j+blockSize));
            for (int ii = i; ii < check; ++ii) {
                for (int jj = j; jj < check2; ++jj) {
                    T[ii][jj] = M[jj][ii];
                    
                }
            }
        }
    }
    }
}


void printMatrix(float **M, int n){
 for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        printf("%.2f  ",M[i][j]);
    }
    printf("\n");
 }
}


void freeMemory(float** M, int n){
	for(int i=0; i<n; i++){
		free(M[i]);
	}
	free(M);
}

void bubbleSort(double sort[], int n) { 
    for (int i = 0; i < n - 1; i++) { 
        for (int j = 0; j < n - i - 1; j++) { 
            if (sort[j] > sort[j + 1]) { 
                double temp = sort[j]; 
                sort[j] = sort[j + 1]; 
                sort[j + 1] = temp; 
            } 
        } 
    } 
} 
 
 
double timeAverage(double sort[], int n) { 
    int range = (int)(n * 0.4); 
    if (range == 0) 
    	return 0.0; 
 
    int starti = (n - range) / 2;  
    int endi = starti + range;  
 
    double sum = 0.0; 
    for (int i = starti; i < endi; i++) { 
    	//printf("sort%d: %.9f", i, sort[i]);
        sum += sort[i]; 
    } 
    return sum / range; 
} 

void checkCorrectness(float **M, float** T, int n){ 
    int tmp = n/4;
    int i=1;
    for(int j=1; j<n; j+=tmp){
      if(M[i][j]!=T[j][i]){
        printf("\n\nError in the transposition!!\n\n");
      }
    }
}

double speedup(double timeSeq, double timeAvg){
	double tmp = 0.0;
	tmp = timeSeq/timeAvg;
	//printf("\nTMP1:%.9f", tmp);
	return tmp; 
}

double efficiency(double speedup, int nthreads){
	double tmp = 0.0;
	tmp = (speedup/nthreads)*100;
	//printf("\nTMP2:%.9f\n", tmp);
	return tmp;
}

void cache_flush() {
 	  size_t cache_size = 1088*1024;
	  char *array = (char*)malloc(cache_size); 
    if (array == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < cache_size; i++) {
        array[i] = 0; 
    }

    free(array);
}

