#ifndef MATRIXMULTIPLY_H
#define MATRIXMULTIPLY_H

int **A; int **B; int **C; int n;
int thread_number;

void print_usage();
int get_num_threads(int argc, char * argv[]);

#endif