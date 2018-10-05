#include <stdlib.h>
#include "include/unit.h"
#include "include/array_functions.h"

int main() {
    test_all();

    size_t width, height;
    int init;
    printf("Input width and height of array and initial value\n");
    int read = scanf("%zu %zu %d", &width, &height, &init);

    int **array = createArray(width, height, 0);
    if (array != NULL && read == 3) {
        fillArray((int** const)array, width, height, init);
        print2DArray((const int** const)array, width, height);
    } else {
        printf("Input error\n");
    }

    if (array != NULL) {
        for (int i = 0; i < height; i++) {
            free(array[i]);
        }
        free(array);
    }
}
