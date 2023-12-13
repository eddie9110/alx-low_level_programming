#ifndef SEARCH_ALGS_H
#define SEARCH_ALGS_H

#include <stdio.h>
#include <stdlib.h>


int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);

void print_ftn(int *arr, int start, int end);

#endif
