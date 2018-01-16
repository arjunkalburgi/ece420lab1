#ifndef MULTIPLY_H
#define MULTIPLY_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include "../DevelopmentKitLab1/lab1_IO.h"
#include "../DevelopmentKitLab1/timer.h"

int **A; int **B; int **C; int n;
int thread_number;

void print_usage();
int get_num_threads(int argc, char * argv[]);

#endif