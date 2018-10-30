#ifndef SORTINGS_H
#define SORTINGS_H

#include <cstddef>
#include <cstdio>
#include <iostream>
#include "utils.hpp"

void bogosort(int *arr, size_t size);
void bubblesort(int *arr, size_t size);
void countsort(char *arr, size_t size);
void heapsort(int *arr, size_t size);
size_t binsearch(int *arr, size_t size, int key);
void quicksort(int *arr, size_t size);
void shuffle(int *arr, size_t size);

#endif //SORTINGS_H
