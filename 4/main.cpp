#include <iostream>
#include <cstdio>
#include "include/unit.h"
#include "include/sortings.h"
#include "include/binaryheap.h"

int main() {
    //test_all();

    //srand(time(0));
    size_t size = 10;
    int *arr = nullptr;

    std::cout << "Random array generated: \n";
    get_random_array(arr, size, 256);
    display(arr, size);

	quicksort(arr, size);

    std::cout << "\nSorted: \n";
    display(arr, size);
    std::cout << "\n";

	int res = binsearch(arr, 0, size, -175);
    std::cout << "Search for -92 via binsearch: " << (int)res << "\n\n";

    return 0;
}
