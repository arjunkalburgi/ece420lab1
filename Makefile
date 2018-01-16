CC := gcc
CFLAGS := -g -Wall -lpthread 

# all: checkdirs matrixgen serialtester main

all: matrix 

makedata: DevelopmentKitLab1/matrixgen
	./DevelopmentKitLab1/matrixgen
	mv data_input DevelopmentKitLab1/

matrix: matrixmultiply.c DevelopmentKitLab1/lab1_IO.c
	$(CC) $^ $(CFLAGS)

clean:
	rm -rf DevelopmentKitLab1/data_input
	rm -rf a.out
