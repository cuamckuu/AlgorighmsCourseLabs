#include "include/binaryheap.h"
#include "include/itterator.h"
#include "include/drawer.h"

void BinaryHeap::draw_node(Drawer &screen, const size_t i, const int x, const int y, const int r) const {
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < size) {
        draw_node(screen, left, x-r, y+1, r/2);
    }

    if (right < size) {
        draw_node(screen, right, x+r, y+1, r/2);
    }

    screen.print_at(x, y, arr[i]);
}

void BinaryHeap::display() const {
    int height = std::log2(size) + 1;
    int width = std::pow(2, height + 2);
    int radius = std::pow(2, height);

    Drawer screen(width, height);
    draw_node(screen, 0, width/2, 0, radius);
    screen.display();
}

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

void BinaryHeap::remove(const int key) {
    _wasChanged = true;

    size_t i;
    bool found = false;
    for (i = 0; i < size; i++) {
        if (arr[i] == key) {
            found = true;
            break;
        }
    }

    if (!found) {
        throw std::invalid_argument("No such key in heap");
    }

    std::swap(arr[i], arr[size-1]);
    size--;
    heapify(i);
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

void BinaryHeap::increase_key(size_t i, const int key) {
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

void BinaryHeap::insert(const int key) {
    // Itterator should be recreated after insertion, cause it's not valid anymore
    _wasChanged = true;

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

size_t BinaryHeap::get_size() const {
    return size;
}

bool BinaryHeap::wasChanged() const {
    return _wasChanged;
}

int BinaryHeap::at(size_t i) const {
    if (i >= size) {
        throw std::out_of_range("Wrong index");
    }

    return arr[i];
}

void BinaryHeap::resetChangesState() {
    _wasChanged = false;
}

Itterator* BinaryHeap::get_dfs_itterator(const size_t start) const {
    return new HeapItteratorDFS(this, start);
}

Itterator* BinaryHeap::get_bfs_itterator(const size_t start) const {
    return new HeapItteratorBFS(this, start);
}

bool BinaryHeap::contains(const int key) const {
    if (key > arr[0]) return false;

    for (size_t i = 0; i < size; i++) {
        if (arr[i] == key) {
            return true;
        }
    }

    return false;
}
