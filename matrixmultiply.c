#include "matrixmultiply.h"

int main (int argc, char * argv[]){

    thread_number = get_num_threads(argc, argv);
 	pthread_t threads[thread_number];

 	Lab1_loadinput(&A, &B, &n);

	create_result_matrix(n);

	double start_time;
	double end_time;
	GET_TIME(start_time);

	int i;
	for (i = 0; i < thread_number; i++){
		pthread_create(&threads[i], NULL, multiplyBlock, INT2VOIDP(i));
	}

	for (i = 0; i < thread_number; i++){
		pthread_join(threads[i], NULL);
	}

	GET_TIME(end_time);

	Lab1_saveoutput(C, &n, end_time - start_time);

	return 0;
}

void* multiplyBlock(void* threadID) {
	int k = (int) threadID;
	int p = thread_number;

	int x = k / sqrt(p);
	int y = (int) k % (int) sqrt(p);

	int row_lower_bound = (n/sqrt(p)) * x;
	int column_lower_bound = (n/sqrt(p)) * y;

	int row_upper_bound = ((n/sqrt(p))*(x+1)) -1;
	int column_upper_bound = ((n/sqrt(p))*(y+1)) -1;

	solve_block(row_lower_bound, column_lower_bound, 
	row_upper_bound, column_upper_bound);
	
	return 0;
}

void solve_block(int row_lower_bound, int column_lower_bound, 
	int row_upper_bound, int column_upper_bound){

	int i;
	int j;

	for (i = row_lower_bound; i <= row_upper_bound ; i++){
		for (j = column_lower_bound; j <= column_upper_bound; j++){
			C[i][j] = multiply_vector(i, j);
		}
	}
}

int multiply_vector(int i, int j){
	int x;

	int sum = 0;
	for (x = 0; x < n; x++){
		sum += A[i][x] * B[x][j];
	}

	return sum;
}

void create_result_matrix(int size){
	C = malloc(size * sizeof(int *));
	int i;
	for (i = 0; i < size; i++){
		C[i] = malloc (size * sizeof(int *));
	}
}
