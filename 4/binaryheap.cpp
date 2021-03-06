#include "include/binaryheap.h"

void BinaryHeap::heapify(const size_t i) {
    if (i >= size) {
        throw std::out_of_range("Heapify wrong index");
    }

    size_t left  = 2 * i + 1;
    size_t right = 2 * i + 2;

    size_t largest = i;

    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(largest);
    }
}

BinaryHeap::BinaryHeap(const int *init_arr, const size_t init_size) {
    if (init_arr == nullptr || init_size == 0) {
        throw std::invalid_argument("Heap from nullptr");
    }

    size = init_size;
    arr = new int[init_size];

    for (size_t i = 0; i < size; i++) {
        arr[i] = init_arr[i];
    }

    for (size_t i = (size - 1) / 2; i > 0; i--) {
        heapify(i);
    }
    heapify(0);
}

BinaryHeap::~BinaryHeap() {
    delete[] arr;
}

void BinaryHeap::heapsort(int *arr_to_sort, const size_t size) {
    BinaryHeap heap(arr_to_sort, size); // Exception here

    for (size_t i = heap.size - 1; i > 0; i--) {
        std::swap(heap.arr[0], heap.arr[i]);
        heap.size--;
        heap.heapify(0);
    }

    for (size_t i = 0; i < size; i++) {
        arr_to_sort[i] = heap.arr[i];
    }
}
