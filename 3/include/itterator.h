#ifndef ITTERATOR_H
#define ITTERATOR_H

#include "binaryheap.h"

class Itterator {
public:
    virtual int next() = 0;
    virtual bool has_next() const = 0;
};

class HeapItteratorDFS : public Itterator {
public:
    HeapItteratorDFS(const BinaryHeap* heap, const size_t start);
    ~HeapItteratorDFS();
    int next() override;
    bool has_next() const override;

    const BinaryHeap *heap;
    bool* visited;
    size_t current;
    size_t initial_size;
};

class HeapItteratorBFS : public Itterator {
public:
    HeapItteratorBFS(const BinaryHeap* heap, const size_t start);
    int next() override;
    bool has_next() const override;

    const BinaryHeap *heap;
    size_t current;
    size_t initial_size;
};

#endif
