#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <utility> // For std::swap
#include <iostream>
#include <cmath>
#include <exception>
#include <limits>

class Itterator;
class Drawer;

class BinaryHeap {
public:
    BinaryHeap(const int *init_arr, const size_t init_size);
    ~BinaryHeap();

    void heapify(const size_t i);
    void increase_key(size_t i, const int key);
    void display() const;
    size_t get_size() const;
    bool wasChanged() const;
    int at(const size_t i) const;
    void resetChangesState();

    static void heapsort(int *arr_to_sort, const size_t sort_size);
    bool contains(const int key) const;
    void insert(const int key);
    void remove(const int key);

    void draw_node(Drawer &screen, const size_t i, const int x, const int y, const int r) const;

    Itterator* get_dfs_itterator(size_t start = 0) const;
    Itterator* get_bfs_itterator(size_t start = 0) const;

private:
    int *arr;
    size_t size;
    bool _wasChanged = false;
};

#endif //BINARYHEAP_H
