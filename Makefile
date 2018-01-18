CC := gcc
CFLAGS := -g -Wall -lpthread -lm -std=gnu99 -O3

all: data matrix run tester test clean 

data: matrixgen
	@./matrixgen

matrix: matrixmultiply.c lab1_IO.c
	@$(CC) $^ $(CFLAGS) -o main

run: 
	@./main 16

tester: serialtester.c lab1_IO.c
	@$(CC) $^ -o serialtester
	
test: 
	@./serialtester

clean:
	@rm -rf data_input
	@rm -rf data_output	
	@rm -rf serialtester
	@rm -rf main
	@rm -rf main.dSYM
