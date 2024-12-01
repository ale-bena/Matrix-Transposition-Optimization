#include "implfunc.h"
#define min(a, b) ((a) < (b) ? (a) : (b))


int isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);  
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

/***************************************
*
* checkSymImp() - checks if a given n x n 
* matrix is symmetric using an improved 
* block-based approach
* input: float** M - pointer to the matrix
*        int n - the size of the matrix 
*        (number of rows and columns)
* output: 1 (true) if the matrix is symmetric,
*         0 (false) otherwise
* notes: divides the matrix into 8x8 blocks to 
*        optimize memory access and performance. 
*        Compares M[i][j] with M[j][i] within each block.
*
***************************************/
int checkSymImp(float** M, int n){
    for (int i = 0; i < n; i += 8) {
        for (int j = 0; j < n; j += 8) {
            int check=min(n, (i+8));
            int check2=min(n, (j+8));
            for (int ii = i; ii < check; ++ii) {
                for (int jj = j; jj < check2; ++jj) {
                    if(M[i][j]!=M[j][i]){
                      return 0;
                    }
                    
                }
            }
        }
    }
    return 1;
}


/***************************************
*
* matTransposeImp() - transposes an n x n 
* matrix using an improved method with loop 
* unrolling for optimization
* input: float** M - pointer to the original matrix
*        float** T - pointer to the transposed matrix
*        int n - the size of the matrix 
*        (number of rows and columns)
* output: none (matrix T is modified in place)
* notes: checks if the matrix M is symmetric using 
*        checkSymImp(). If not symmetric, performs 
*        the transposition with loop unrolling (by 8) 
*        to enhance performance. Handles any remainder 
*        elements after unrolling.
*
***************************************/
void matTransposeImp(float** M, float** T, int n) {
    if(checkSymImp(M,n)==0){
    for (int i = 0; i < n; ++i) {
        int j;
        for (j=0; j <= n - 8; j += 8) { // Unroll by 8
            T[i][j] = M[j][i];
            T[i][j + 1] = M[j + 1][i];
            T[i][j + 2] = M[j + 2][i];
            T[i][j + 3] = M[j + 3][i];
            T[i][j + 4] = M[j + 4][i];
            T[i][j + 5] = M[j + 5][i];
            T[i][j + 6] = M[j + 6][i];
            T[i][j + 7] = M[j + 7][i];
        }
        for (; j < n; ++j) { // Handle the remainder
            T[i][j] = M[j][i];
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

