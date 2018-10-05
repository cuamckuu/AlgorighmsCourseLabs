#include <stdio.h>
#include <stdlib.h>
#include "include/unit.h"
#include "include/array_functions.h"

void test_create_func_pos_size() {
    int **arr = createArray(10, 5, 0);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            // All cells are available
            arr[i][j] = 77;
        }
    }

    assert(arr != NULL);
    for (int i = 0; i < 5; i++) {
        free(arr[i]);
    }

    free(arr);
}

void test_create_func_neg_size() {
    int **arr1 = createArray(-10, 5, 0);
    assert(arr1 == NULL);

    int **arr2 = createArray(10, -5, 0);
    assert(arr2 == NULL);

    int **arr3 = createArray(-10, -5, 0);
    assert(arr3 == NULL);
}

void test_equal_func_equal_arrays() {
    int **arr1 = createArray(3, 3, 0);
    int **arr2 = createArray(3, 3, 0);

    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr1[i][j] = cnt;
            arr2[i][j] = cnt;
            cnt++;
        }
    }

    assert(is_equal((const int** const)arr1, 3, 3,
                    (const int** const)arr2, 3, 3) == true);
}

void test_equal_func_diff_arrays() {
    int **arr1 = createArray(3, 3, 0);
    int **arr2 = createArray(3, 3, 0);

    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr1[i][j] = cnt;
            arr2[j][i] = cnt;
            cnt++;
        }
    }

    assert((bool)is_equal((const int** const)arr1, 3, 3
                         ,(const int** const)arr2, 3, 3) == false);
}

void test_equal_func_diff_sizes() {
    int **arr1 = createArray(3, 3, 0);
    int **arr2 = createArray(2, 3, 0);
    int **arr3 = createArray(3, 2, 0);

    assert(is_equal((const int** const)arr1, 3, 3
                   ,(const int** const)arr2, 2, 3) == false);

    assert(is_equal((const int** const)arr1, 3, 3
                   ,(const int** const)arr3, 3, 2) == false);

    assert(is_equal((const int** const)arr2, 2, 3
                   ,(const int** const)arr3, 3, 2) == false);
}

void test_fill_func_dim1() {
    int **arr1 = createArray(1, 1, 0);
    int **arr2 = createArray(1, 1, 1);

    fillArray(arr1, 1, 1, 1);
    assert(is_equal((const int** const)arr1, 1, 1
                   ,(const int** const)arr2, 1, 1) == true);
}

void test_fill_func_dim2() {
    int **arr1 = createArray(2, 2, 0);
    int **arr2 = createArray(2, 2, 0);
    arr2[0][0] = 1;
    arr2[0][1] = 2;
    arr2[1][0] = 3;
    arr2[1][1] = 4;

    fillArray(arr1, 2, 2, 1);

    assert(is_equal((const int** const)arr1, 2, 2
                   ,(const int** const)arr2, 2, 2) == true);
}

void test_fill_func_dim32() {
    int **arr1 = createArray(3, 2, 0);
    int **arr2 = createArray(3, 2, 0);
    arr2[0][0] = 1;
    arr2[0][1] = 2;
    arr2[1][0] = 3;
    arr2[0][2] = 4;
    arr2[1][1] = 5;
    arr2[1][2] = 6;

    fillArray(arr1, 3, 2, 1);

    assert(is_equal((const int** const)arr1, 2, 2
                   ,(const int** const)arr2, 2, 2) == true);
}

void test_all() {
    //====TEST createArray()====
    test_create_func_pos_size();
    test_create_func_neg_size();

    //====TEST is_equal()=======
    test_equal_func_equal_arrays();
    test_equal_func_diff_arrays();
    test_equal_func_diff_sizes();

    //====TEST fillArray()======
    test_fill_func_dim1();
    test_fill_func_dim2();
    test_fill_func_dim32();
}
