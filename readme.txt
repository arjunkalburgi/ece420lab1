## ECE 420 Lab 1
### Authors: Abid Rahman (1428636), Arjun Kalburgi (1388774)

# Multithreaded implementation of matrix multiply.

## Run instructions:

> `make matrix` <!--build .main file -->
> `./main <number of threads>` <!-- run program -->


## Other instructions:
### Testing functionality of the program is all automated 
### through the Makefile. Breakdown: 

> `make data` <!-- create data_input file -->
> `make matrix` <!-- create main exe -->
> `make run` <!-- run program -->
> `make tester` <!-- makes serial tester -->
> `make test` <!-- runs serial tester -->
> `make clean` <!-- remove all additional files -->

### Additionally 
> `make all` <!-- does all the above steps in one -->
> './check.sh' <!-- runs the check script to test for times -->
