#include <iostream>
#include <cstdio>
#include "include/unit.h"
#include "include/sortings.h"
#include "../3/include/binaryheap.h"

int main() {
    test_all();

    //srand(time(0));
    size_t size = 10;
    char *arr = nullptr;

    BinaryHeap::heapsort(new int[10], size);

    std::cout << "Random array generated: \n";
    get_random_array(arr, size, 256);
    display(arr, size);

	countsort(arr, size);

    std::cout << "\nSorted via countsort: \n";
    display(arr, size);
    std::cout << "\n";

	size_t res = binsearch(arr, 0, size, -92);
    std::cout << "Search for -92 via binsearch: " << (int)res << "\n\n";

	res = binsearch(arr, 0, size, 111);
    std::cout << "Search for 111 via binsearch: " << (int)res << "\n\n";

    return 0;
}
