//---------------------------------------------//
// ECE 420 Lab 1
// Abid Rahman and Arjun Kalburgi
// January, 2018
// Filename: matrixmultiply.h
//		- Header file for main program
//---------------------------------------------//

#ifndef MATRIXMULTIPLY_H
#define MATRIXMULTIPLY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include <math.h>
#include "lab1_IO.h"
#include "timer.h"

int **A; int **B; int **C; int n;
int static thread_number;
int static rootp;

#define INT2VOIDP(i) (void *)(uintptr_t)(i)

int multiply_vector(int i, int j);
void* calculateMatrixBlock(void* threadID);

int get_num_threads(int argc, char *argv[]);
void print_usage();

#endif