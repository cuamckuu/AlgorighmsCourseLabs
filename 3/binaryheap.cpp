#include "include/binaryheap.h"
#include "include/itterator.h"

bool is_power_of_2(int n) {
    return n > 0 && (n & (n-1)) == 0;
}

void BinaryHeap::display() {
    // TODO: Use BFS itteratorator
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

void BinaryHeap::remove(int key) {
    size_t i;
    bool found = false;
    for (i = 0; i < size; i++) {
        if (arr[i] == key) {
            break;
            found = true;
        }
    }

    if (!found) {
        throw std::invalid_argument("No such key in heap");
    }

    std::swap(arr[i], arr[size-1]);
    size--;
    heapify(i);
}

BinaryHeap::BinaryHeap(int *init_arr, size_t init_size) {
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

void BinaryHeap::heapsort(int *arr_to_sort, size_t size) {
    BinaryHeap heap(arr_to_sort, size);

    for (size_t i = heap.size - 1; i > 0; i--) {
        std::swap(heap.arr[0], heap.arr[i]);
        heap.size--;
        heap.heapify(0);
    }

    for (size_t i = 0; i < size; i++) {
        arr_to_sort[i] = heap.arr[i];
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
    // Itterator should be recreated after insertion, cause it's not valid anymore

    size++;

    int *prev = arr;
    arr = new int[size];

    for (size_t i = 0; i < size - 1; i++) {
        arr[i] = prev[i];
    }

    arr[size-1] = std::numeric_limits<int>::min();
    increase_key(size-1, key);

    delete[] prev;
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

Itterator* BinaryHeap::get_dfs_itterator(size_t start) {
    return new HeapItteratorDFS(this, start);
}

Itterator* BinaryHeap::get_bfs_itterator(size_t start) {
    return new HeapItteratorBFS(this, start);
}

bool BinaryHeap::contains(int key) {
    if (key > arr[0]) return false;

    Itterator *itterator = get_bfs_itterator();

    while (itterator->has_next()) {
        int curr = itterator->next();

        if (curr == key) {
            return true;
        }
    }

    return false;
}
