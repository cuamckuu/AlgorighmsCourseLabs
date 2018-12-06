#include "include/unit.h"
#include "include/sortings.h"
#include "include/binaryheap.h"

void test_is_sorted() {
    int arr1[] = {1, 2, 3, 4, 5, 6};
    int arr2[] = {1, 3, 2, 4, 6, 5};

    int *parr1 = arr1;
    int *parr2 = arr2;

    assert(is_sorted(parr1, 6));
    assert(!is_sorted(parr2, 6));
}

void test_bogosort() {
    int arr1[] = {1, 3, 2, 4, 6, 5};
    int *parr1 = &arr1[0];

    assert(!is_sorted(parr1, 6));
    bogosort(parr1, 6);
    assert(is_sorted(parr1, 6));

    int arr2[] = {5};
    int *parr2 = &arr1[0];

    bogosort(parr2, 1);
    assert(is_sorted(parr2, 1));
}

void test_bubblesort() {
    int arr1[] = {1, 3, 2, 4, 6, 5};
    int *parr1 = &arr1[0];

    assert(!is_sorted(parr1, 6));
    bubblesort(parr1, 6);
    assert(is_sorted(parr1, 6));

    int arr2[] = {5};
    int *parr2 = &arr1[0];

    bubblesort(parr2, 1);
    assert(is_sorted(parr2, 1));
}

void test_heapsort() {
    int arr1[] = {1, 3, 2, 4, 6, 5};
    int *parr1 = &arr1[0];

    assert(!is_sorted(parr1, 6));
    BinaryHeap::heapsort(parr1, 6);
    assert(is_sorted(parr1, 6));

    int arr2[] = {5};
    int *parr2 = &arr1[0];

    BinaryHeap::heapsort(parr2, 1);
    assert(is_sorted(parr2, 1));
}

void test_binsearch() {
    int arr1[] = {-2, -1, 3, 4, 5, 6};
    int *parr1 = &arr1[0];
    size_t size = 6;

    assert(is_sorted(parr1, size));

    int res;
    res = binsearch(arr1, 0, size, -2);
    assert(res == 0);

    res = binsearch(arr1, 0, size, -1);
    assert(res == 1);

    res = binsearch(arr1, 0, size, 3);
    assert(res == 2);

    res = binsearch(arr1, 0, size, 4);
    assert(res == 3);

    res = binsearch(arr1, 0, size, 5);
    assert(res == 4);

    res = binsearch(arr1, 0, size, 6);
    assert(res == 5);

    res = binsearch(arr1, 0, size, -123);
    assert(res == -1);
}

void test_quicksort() {
    int arr1[] = {1, 3, 2, 4, 6, 5};
    int *parr1 = &arr1[0];

    assert(!is_sorted(parr1, 6));
    quicksort(parr1, 6);
    assert(is_sorted(parr1, 6));

    int arr2[] = {5};
    int *parr2 = &arr1[0];

    quicksort(parr2, 1);
    assert(is_sorted(parr2, 1));
}

void test_countsort() {
    char arr1[] = {-1, 3, 2, -4, 6, 5};
    char *parr1 = &arr1[0];

    assert(!is_sorted(parr1, 6));
    countsort(parr1, 6);
    assert(is_sorted(parr1, 6));

    char arr2[] = {5};
    char *parr2 = &arr1[0];

    countsort(parr2, 1);
    assert(is_sorted(parr2, 1));
}

void test_shuffle() {
    int arr1[] = {1, 3, 2, 4, 6, 5};
    int *parr1 = &arr1[0];

    assert(!is_sorted(parr1, 6));
    bubblesort(parr1, 6);
    assert(is_sorted(parr1, 6));
    shuffle(parr1, 6);
    assert(!is_sorted(parr1, 6));
}

void test_all() {
    test_is_sorted();

    test_bogosort();
    test_bubblesort();
    test_heapsort();
    test_binsearch();
    test_quicksort();
    test_countsort();

    test_shuffle();
}
