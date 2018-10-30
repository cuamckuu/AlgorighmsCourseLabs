#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <utility> // For std::swap
#include <iostream>
#include <cmath>
#include <exception>
#include <limits>

class Itterator;

class BinaryHeap {
public:
    BinaryHeap(int *init_arr, size_t init_size);
    ~BinaryHeap();

    void heapify(size_t i);
    static void heapsort(int *arr_to_sort, size_t sort_size);
    void increase_key(size_t i, int key);
    void insert(int key);
    int pop_max();
    void display();
    size_t get_size();
    int at(size_t i);
    bool contains(int key);

    Itterator* get_dfs_itterator(size_t start = 0);
    Itterator* get_bfs_itterator(size_t start = 0);

private:
    int *arr;
    size_t size;
};

#endif //BINARYHEAP_H
