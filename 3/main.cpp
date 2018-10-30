#include <iostream>
#include "include/binaryheap.h"
#include "include/itterator.h"
#include "include/unit.h"

int main() {
    test_all();

    size_t size = 5;
    int *arr = new int[size];
    std::cout << "Initial array: ";
    for (int i = 0; i < size; i++) {
        arr[i] = i;
        std::cout << arr[i] << " ";
    }
    std::cout << "\n\n";

    BinaryHeap temp(arr, size);
    std::cout << "Heap Display:  ";
    temp.display();

    std::cout << "BFS Itterator: ";
    Itterator *itter1 = temp.get_bfs_itter();
    while(itter1->has_next()) {
        std::cout << itter1->next() << " ";
    }

    std::cout << "\nDFS Itterator: ";
    Itterator *itter2 = temp.get_dfs_itter();
    while(itter2->has_next()) {
        std::cout << itter2->next() << " ";
    }
    std::cout << "\n\n";

    std::cout << "Heap contains 10: " << temp.contains(10) << "\n\n";

    std::cout << "Change third element to 10: \n";
    temp.increase_key(3, 10);
    temp.display();
    std::cout << "\n";
    std::cout << "Heap contains 10: " << temp.contains(10) << "\n\n";

    std::cout << "Insert 11 to heap: \n";
    temp.insert(11);
    temp.display();
    std::cout << "P.S.: Initial array and heap's array not the same anymore\n\n";

    std::cout << "Pop max, should be fixed due to spec: \n";
    std::cout << temp.pop_max() << "\n\n";

    std::cout << "Heapsort for initial array: \n";
    BinaryHeap::heapsort(arr, size);
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
