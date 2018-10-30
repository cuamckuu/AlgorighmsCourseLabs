#include <iostream>
#include <cstdio>
#include "include/unit.h"
#include "include/sortings.h"

int main() {
    test_all();

    srand(time(0));
    size_t size = 10;
    char *arr = nullptr;

    get_random_array(arr, size, 256);
    display(arr, size);

    //bogosort(arr, size);
    //bubblesort(arr, size);
	//heapsort(arr, size);
	//binsearch(arr, 0, size, key);
	//countsort(arr, size);
    display(arr, size);

    return 0;
}
