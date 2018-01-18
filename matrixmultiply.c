//---------------------------------------------//
// ECE 420 Lab 1
// Abid Rahman and Arjun Kalburgi
// January, 2018
// Filename: matrixmultiply.c
//		- Handles main program logic
//---------------------------------------------//
#include "matrixmultiply.h"

int main (int argc, char * argv[]){

    thread_number = get_num_threads(argc, argv);
 	pthread_t threads[thread_number];

	//Load the input data
 	Lab1_loadinput(&A, &B, &n);

	//Allocate memory for output matrix
	C = malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++){
		C[i] = malloc (n * sizeof(int *));
	}

	//Get initial time
	double start_time, end_time;
	GET_TIME(start_time);

	//Make threads to calculate matrix
	for (int i = 0; i < thread_number; i++) {
		pthread_create(&threads[i], NULL, calculateMatrixBlock, INT2VOIDP(i));
	}

	//Join all the threads
	for (int i = 0; i < thread_number; i++) {
		pthread_join(threads[i], NULL);
	}

	//Get ending time
	GET_TIME(end_time);

	//Save output matrix
	Lab1_saveoutput(C, &n, end_time - start_time);

	return 0;
}

void* calculateMatrixBlock(void* threadID) {
	unsigned int k = (uintptr_t) threadID;
	int p = thread_number;
	int rootp = sqrt(p);

	int x = k / rootp;
	int y = (int) k % (int) rootp;

	int row_lower_bound = (n/rootp) * x;
	int column_lower_bound = (n/rootp) * y;

	int row_upper_bound = ((n/rootp)*(x+1)) -1;
	int column_upper_bound = ((n/rootp)*(y+1)) -1;

	for (int i = row_lower_bound; i <= row_upper_bound ; i++) {
		for (int j = column_lower_bound; j <= column_upper_bound; j++) {
			C[i][j] = multiply_vector(i, j);
		}
	}
	
	return 0;
}

int multiply_vector(int i, int j) {
	int sum = 0;

	for (int x = 0; x < n; x++) {
		sum += A[i][x] * B[x][j];
	}

	return sum;
}

int get_num_threads(int argc, char **argv) {

    if (argc != 2) {
        printf("Incorrect number of arguments.\n");
        print_usage();
        exit(EXIT_FAILURE);
    }

    //Get number of threads argument from user
    int num_threads = atoi(argv[1]);

    if (num_threads < 1)
    {
        printf("Invalid number of threads entered. Must be > 1.\n");
        print_usage();
        exit(EXIT_FAILURE);
    }
    else
    {
        int temp = sqrt(num_threads);
        if (temp * temp != num_threads) {
            printf("Invalid number of threads entered. Must be a perfect square.\n");
            print_usage();
            exit(EXIT_FAILURE);
        }
    }
    return num_threads;
}

void print_usage() {
    printf("USAGE: multiply <number of threads (perfect square)> \n");
}