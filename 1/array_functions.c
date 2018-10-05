#include <stdio.h>
#include <stdlib.h>
#include "include/array_functions.h"

void print2DArray(const int const **array, size_t width, size_t height) {
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            printf("\t%d", array[i][j]);
        }

        printf("\n");
    }
}

void fillArray(int ** const array, size_t width, size_t height, int init) {
    int counter = init;

    for (size_t k = 0; k < (width + height); ++k) {
        for (size_t i = 0; i <= k; ++i) {
            size_t j = k - i;

            if (i < height && j < width) {
                array[i][j] = counter;
                counter++;
            }
        }
    }
}

int** createArray(size_t width, size_t height, int fill) {
    int **array = (int **)malloc(height * sizeof(int *));

    if (array == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < height; ++i) {
        array[i] = (int *)malloc(width * sizeof(int));

        if (array[i] == NULL) {
            for (size_t j = 0; j < i; ++j) {
                free(array[i]);
            }
            return NULL;
        }

        for (size_t j = 0; j < width; ++j) {
            array[i][j] = fill;
        }
    }

    return array;
}

bool is_equal(const int** const arr1, size_t width1, size_t height1,
              const int** const arr2, size_t width2, size_t height2)
{
    if (width1 != width2 || height1 != height2) {
        return false;
    }

    for (size_t i = 0; i < height1; ++i) {
        for (size_t j = 0; j < width1; ++j) {
            if (arr1[i][j] != arr2[i][j]) {
                return false;
            }
        }
    }

    return true;
}
