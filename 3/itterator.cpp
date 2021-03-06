#include "include/itterator.h"

HeapItteratorDFS::HeapItteratorDFS(const BinaryHeap *heap, const size_t start)
    :heap(heap)
    ,current(start)
{
    initial_size = heap->get_size();

    visited = new bool[initial_size];
    for (size_t i = 0; i < initial_size; i++) {
        visited[i] = 0;
    }
}

HeapItteratorDFS::~HeapItteratorDFS() {
    delete[] visited;
}

int HeapItteratorDFS::next() {
    if (!has_next()) {
        throw std::out_of_range("Next element doesn't exist");
    }

    size_t size = heap->get_size();
    int curr_key = heap->at(current);
    visited[current] = 1;

    while (visited[current] && has_next()) {
        size_t left  = current * 2 + 1;
        size_t right = current * 2 + 2;

        if (left < size && !visited[left]) {
            current = left;
        } else if (right < size && !visited[right]) {
            current = right;
        } else {
            size_t parrent = (current - 1) / 2;
            current = (current == 0 ? 0 : parrent);
        }
    }

    return curr_key;
}

bool HeapItteratorDFS::has_next() const {
    bool all_visited = true;

    for (size_t i = 0; i < (heap->get_size()); i++) {
        all_visited &= visited[i];
    }

    return !all_visited && !(heap->wasChanged());
}

HeapItteratorBFS::HeapItteratorBFS(const BinaryHeap *heap, const size_t start)
    :heap(heap)
    ,current(start)
{
    initial_size = heap->get_size();
}

int HeapItteratorBFS::next() {
    if (!has_next()) {
        throw std::out_of_range("Next element doesn't exist");
    }

    current++;
    return heap->at(current-1);
}

bool HeapItteratorBFS::has_next() const {
    size_t current_size = heap->get_size();

    return (current < current_size) && !(heap->wasChanged());
}

