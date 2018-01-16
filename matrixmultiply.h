#ifndef MATRIXMULTIPLY_H
#define MATRIXMULTIPLY_H

int **A; int **B; int **C; int n;
int thread_number;

void print_usage();
int get_num_threads(int argc, char * argv[]);
void create_result_matrix(int size);
int multiply_vector(int i, int j);
void solve_block(int row_lower_bound, int column_lower_bound, 
	int row_upper_bound, int column_upper_bound);
void* multiplyBlock(void* threadID);

#endif