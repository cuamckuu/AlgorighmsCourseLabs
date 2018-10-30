#ifndef ITTERATOR_H
#define ITTERATOR_H

#include "binaryheap.h"

class Itterator {
public:
    virtual int next() = 0;
    virtual bool has_next() = 0;
};

class HeapItteratorDFS : public Itterator {
public:
    HeapItteratorDFS(BinaryHeap* heap, size_t start);
    ~HeapItteratorDFS();
    int next() override;
    bool has_next() override;

    BinaryHeap *heap;
    bool* visited;
    size_t current;
};

class HeapItteratorBFS : public Itterator {
public:
    HeapItteratorBFS(BinaryHeap* heap, size_t start);
    int next() override;
    bool has_next() override;

    BinaryHeap *heap;
    size_t current;
};

#endif
