#include <iostream>
#include <cstdio>
#include <ctime>
#include <fstream>

//Александр Красильников
#include "include/unit.h"
#include "include/sortings.h"
#include "include/binaryheap.h"

int main() {
    test_all();

    size_t size = 10;
    std::ofstream fout("data/" + std::to_string(size) + ".txt");

    for (int i = 0; i < 1; i++) {
        srand(time(0));

        int *arr1 = nullptr;
        get_random_array(arr1, size, 256);

        int *arr2 = new int[size];
        for (size_t i = 0; i < size; i++) {
            arr2[i] = arr1[i];
        }

        clock_t begin = clock();
        quicksort(arr1, size);
        clock_t end = clock();

        fout << std::fixed;
        double q_time = double(end-begin) / CLOCKS_PER_SEC;
        fout << "Quicksort time: " << q_time << "\n";

        begin = clock();
        bubblesort(arr2, size);
        end = clock();

        double b_time = double(end-begin) / CLOCKS_PER_SEC;
        fout << "Bubblesort time: " << b_time << "\n";

        //std::cout << "QSort is faster in " << b_time / q_time << " times\n";
    }
    return 0;
}
