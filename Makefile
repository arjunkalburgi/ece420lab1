CC := gcc
CFLAGS := -g -Wall -lpthread 

all: data matrix run test clean 

data: DevelopmentKitLab1/matrixgen
	@./DevelopmentKitLab1/matrixgen

matrix: matrixmultiply.c DevelopmentKitLab1/lab1_IO.c helper/helper.c
	@$(CC) $^ $(CFLAGS) -o main

run: 
	@./main 4

test: DevelopmentKitLab1/serialtester.c DevelopmentKitLab1/lab1_IO.c helper/helper.c
	@$(CC) $^ -o serialtester
	@./serialtester

clean:
	@rm -rf data_input
	@rm -rf data_output	
	@rm -rf serialtester
	@rm -rf main
	@rm -rf main.dSYM
