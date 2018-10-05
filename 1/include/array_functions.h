#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H

#include <stdio.h>
#include <stdbool.h>

void print2DArray(const int const **array, size_t width, size_t height);
void fillArray(int ** const array, size_t width, size_t height, int init);
int** createArray(size_t width, size_t height, int fill);

bool is_equal(const int** const arr1, size_t width1, size_t height1,
              const int** const arr2, size_t width2, size_t height2);

#endif //ARRAY_FUNCTIONS_H
