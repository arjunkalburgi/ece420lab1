CC := gcc
CFLAGS := -g -Wall -lpthread 

all: runtest 

makedata: DevelopmentKitLab1/matrixgen
	@./DevelopmentKitLab1/matrixgen

matrix: matrixmultiply.c DevelopmentKitLab1/lab1_IO.c
	@$(CC) $^ $(CFLAGS) -o main

runmatrix: 
	@./main 4

test: DevelopmentKitLab1/serialtester.c DevelopmentKitLab1/lab1_IO.c
	@$(CC) $^ -o serialtester
	@./serialtester

runtest: makedata matrix runmatrix test clean

clean:
	@rm -rf data_input
	@rm -rf data_output	
	@rm -rf serialtester
	@rm -rf a.out
