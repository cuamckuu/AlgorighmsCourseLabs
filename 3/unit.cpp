#include "include/unit.h"
#include "include/itterator.h"
#include "include/binaryheap.h"

int *arr1 = new int[1];
int *arr2 = new int[2];
int *arr3 = new int[3];

void test_heap_from_array() {
    BinaryHeap temp1(arr1, 1);
    assert(("Heap from array size 1", temp1.at(0) == 1));

    BinaryHeap temp2(arr2, 2);
    assert(("Heap from array size 2" ,temp2.at(0) == 2));
    assert(("Heap from array size 2" ,temp2.at(1) == 1));

    BinaryHeap temp3(arr3, 3);
    assert(("Heap from array size 3" ,temp3.at(0) == 3));
    assert(("Heap from array size 3" ,temp3.at(1) == 2));
    assert(("Heap from array size 3" ,temp3.at(2) == 1));

    try {
        BinaryHeap temp4(nullptr, 100);
    } catch (std::exception e) {
        return;
    }
    assert(false);
}

void test_heapsort() {
    int *arr4 = new int[4];
    arr4[0] = 8;
    arr4[1] = 1;
    arr4[2] = 2;
    arr4[3] = 6;

    BinaryHeap::heapsort(arr4, 4);

    assert(("Heapsort array size 4" ,arr4[0] == 1));
    assert(("Heapsort array size 4" ,arr4[1] == 2));
    assert(("Heapsort array size 4" ,arr4[2] == 6));
    assert(("Heapsort array size 4" ,arr4[3] == 8));
}

void test_increase_key() {
    BinaryHeap temp3(arr3, 3);

    temp3.increase_key(2, 10);
    assert(("Increase key test" ,temp3.at(0) == 10));
    assert(("Increase key test" ,temp3.at(1) == 2));
    assert(("Increase key test" ,temp3.at(2) == 3));
}

void test_contains() {
    BinaryHeap temp3(arr3, 3);

    assert(temp3.contains(1));
    assert(temp3.contains(2));
    assert(temp3.contains(3));
    assert(!temp3.contains(10));

    temp3.increase_key(2, 10);

    assert(temp3.contains(10));
    assert(temp3.contains(2));
    assert(temp3.contains(3));
}

void test_insert() {
    BinaryHeap temp3(arr3, 3);

    assert(temp3.contains(1));
    assert(temp3.contains(2));
    assert(temp3.contains(3));
    assert(!temp3.contains(10));

    temp3.insert(10);
    assert(temp3.at(0) == 10);
    assert(temp3.at(1) == 3);
    assert(temp3.at(2) == 1);
    assert(temp3.at(3) == 2);

    assert(temp3.contains(10));
    assert(temp3.contains(3));
    assert(temp3.contains(1));
    assert(temp3.contains(2));
}

void test_remove() {
    BinaryHeap temp3(arr3, 3);

    temp3.insert(10);

    assert(temp3.contains(1));
    temp3.remove(1);
    assert(!temp3.contains(1));

    assert(temp3.contains(10));
    temp3.remove(10);
    assert(!temp3.contains(10));

    try {
        temp3.remove(2000);
    } catch(std::exception e) {
        return;
    }
    assert(false);
}

void test_bfs_itterator() {
    BinaryHeap temp3(arr3, 3);
    temp3.insert(10);
    temp3.resetChangesState();

    Itterator *itter = temp3.get_bfs_itterator();

    assert(itter->has_next());
    assert(itter->next() == 10);

    assert(itter->has_next());
    assert(itter->next() == 3);

    assert(itter->has_next());
    assert(itter->next() == 1);

    assert(itter->has_next());
    assert(itter->next() == 2);

    assert(!itter->has_next());

    try {
        itter->next();
    } catch(std::exception e) {
        return;
    }
    assert(false);
}

void test_dfs_itterator() {
    BinaryHeap temp3(arr3, 3);
    temp3.insert(10);
    temp3.resetChangesState();

    Itterator *itter = temp3.get_dfs_itterator();

    assert(itter->has_next());
    assert(itter->next() == 10);

    assert(itter->has_next());
    assert(itter->next() == 3);

    assert(itter->has_next());
    assert(itter->next() == 2);

    assert(itter->has_next());
    assert(itter->next() == 1);

    assert(!itter->has_next());

    try {
        itter->next();
    } catch(std::exception e) {
        return;
    }
    assert(false);
}

void test_all() {
    arr1[0] = arr2[0] = arr3[0] = 1;
    arr2[1] = arr3[1] = 2;
    arr3[2] = 3;

    test_heap_from_array();
    test_heapsort();
    test_increase_key();
    test_contains();
    test_insert();
    test_remove();

    test_bfs_itterator();
    test_dfs_itterator();

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
}
