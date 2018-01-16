#ifndef MULTIPLY_H
#define MULTIPLY_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include "utilities.h"
// #include "../sdk/lab1_IO.h"
// #include "../sdk/timer.h"


// The function passed to pthread_create
// Params: threadID
void* multiplyBlock(void*);

// The function to parse the number of threads from the command line
// Params: int argc, char** argv
int parse_number_threads(int, char**);

//Prints the usage of the binary from the terminal
void print_usage();

// Tests if the input int is a square number
// Params: int number to check
int check_square(int);

// Solves a block in the result matrix
// Params: int row lower bound, int column lower bound,
// int row upper bound, int column upper bound
void solve_block(int, int, int, int);

// Multiply the vectors in matracies A and B that corrispond
// to elemnt i and j in result matrix C (Cij)
// Params: int i, int j
int multiply_vector(int, int);

// Creates a size x size result matrix C 
// Params: int size
void create_result_matrix(int);

#endif