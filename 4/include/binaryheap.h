#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <utility> // For std::swap
#include <iostream>
#include <exception>

class BinaryHeap {
public:
    BinaryHeap(const int *init_arr, const size_t init_size);
    ~BinaryHeap();

    void heapify(const size_t i);
    static void heapsort(int *arr_to_sort, const size_t sort_size);

private:
    int *arr;
    size_t size;
};

#endif //BINARYHEAP_H
