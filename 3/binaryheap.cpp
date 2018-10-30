#include "include/binaryheap.h"
#include "include/itterator.h"

bool is_power_of_2(int n) {
    return n > 0 && (n & (n-1)) == 0;
}

void BinaryHeap::display() {
    // TODO: Use BFS itterator
    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void BinaryHeap::heapify(size_t i) {
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

BinaryHeap::BinaryHeap(int *init_arr, size_t init_size) {
    size = init_size;
    arr = init_arr;

    for (size_t i = (size - 1) / 2; i > 0; i--) {
        heapify(i);
    }
    heapify(0);
}

void BinaryHeap::heapsort(int *arr_to_sort, size_t size) {
    BinaryHeap heap(arr_to_sort, size);

    for (size_t i = heap.size - 1; i > 0; i--) {
        std::swap(heap.arr[0], heap.arr[i]);
        heap.size--;
        heap.heapify(0);
    }
}

void BinaryHeap::increase_key(size_t i, int key) {
    if (key < arr[i]) {
        throw std::invalid_argument("Key shouldn't be higher than i'th value");
    }

    arr[i] = key;

    size_t parrent = (i - 1) / 2 ;
    while (i > 0 && arr[parrent] < arr[i]) {
        std::swap(arr[i], arr[parrent]);
        i = parrent;
        parrent = (i - 1) / 2;
    }
}

void BinaryHeap::insert(int key) {
    // User shoud handle own arrays allocations, so no memory cleanup for prev arr
    size++;

    int *prev = arr;
    arr = new int[size];

    for (size_t i = 0; i < size - 1; i++) {
        arr[i] = prev[i];
    }

    arr[size-1] = std::numeric_limits<int>::min();
    increase_key(size-1, key);
}

int BinaryHeap::pop_max() {
    // Raw arrays aren't best choice for that kind of stuff

    if (size == 0) {
        throw std::out_of_range("Nothing to pop");
    }

    int max = arr[0];

    arr[0] = arr[size-1];
    size--;
    heapify(0);

    return max;
}

size_t BinaryHeap::get_size() {
    return size;
}

int BinaryHeap::at(size_t i) {
    if (i >= size) {
        throw std::out_of_range("Wrong index");
    }

    return arr[i];
}

Itterator* BinaryHeap::get_dfs_itter() {
    return new HeapItteratorDFS(this, 0);
}

Itterator* BinaryHeap::get_bfs_itter() {
    return new HeapItteratorBFS(this, 0);
}

bool BinaryHeap::contains(int key) {
    if (key > arr[0]) return false;

    Itterator *itter = get_bfs_itter();

    while (itter->has_next()) {
        int curr = itter->next();

        if (curr == key) {
            return true;
        }
    }

    return false;
}
