#include "helper.h"

void print_usage()
{
    printf("USAGE: multiply <number of threads (perfect square)> \n");
}

int get_num_threads(int argc, char **argv)
{

    if (argc != 2)
    {
        printf("Incorrect number of arguments.\n");
        print_usage();
        exit(EXIT_FAILURE);
    }

    //Get number of threads argument from user
    int num_threads = atoi(argv[1]);

    if (num_threads < 1)
    {
        printf("Invalid number of threads entered. Must be > 1.\n");
        print_usage();
        exit(EXIT_FAILURE);
    }
    else
    {
        int temp = sqrt(num_threads);
        if (temp * temp != num_threads)
        {
            printf("Invalid number of threads entered. Must be a perfect square.\n");
            print_usage();
            exit(EXIT_FAILURE);
        }
    }
    return num_threads;
}