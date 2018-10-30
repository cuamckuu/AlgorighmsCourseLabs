#include <iostream>
#include <cstdio>
#include "include/unit.h"

template<typename T>
void get_random_array(T *&arr, size_t size, int max) {
    if (arr == nullptr || arr == NULL) {
        arr = new T[size];
    }

    for (size_t i = 0; i < size; i++) {
        arr[i] = rand() % max;
    }
}

template<typename T>
void display(T *arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        std::cout << (int) arr[i] << " ";
    }
    std::cout << "\n";
}

template<typename T>
bool is_sorted(T *arr, size_t size) {
    bool sorted = true;
    for (size_t i = 0; i < size - 1; i++) {
        sorted &= (arr[i] < arr[i+1]);
    }

    return sorted;
}

void shuffle(int *arr, size_t size) {
    for (size_t i = size-1; i > 0; i--) {
        size_t j = rand() % (i+1);
        std::swap(arr[i], arr[j]);
    }
}

void bogosort(int *arr, size_t size) {
    while(!is_sorted(arr, size)) {
        shuffle(arr, size);
    }
}

void bubblesort(int *arr, size_t size) {
    for (size_t i = 0; i < size-1; i++) {
        for (size_t j = 0; j < size-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

void insertionsort(int *arr, size_t size) {
}

void countsort(unsigned char *arr, size_t size) {
	// Offset 127?

	int *counter = new int[256];

	for (size_t i = 0; i < size; i++) {
		counter[arr[i]]++;
	}

	size_t cnt = 0;
	for (int i = 0; i < 256; i++) {
		for (int j = 0; j < counter[i]; j++) {
			arr[cnt] = i;
			cnt++;
		}
	}
}

void heapsort(int *arr, size_t size) {
	// В лабе 3
}

int main() {
    test_all();

    srand(time(0));
    size_t size = 10;
    unsigned char *arr = nullptr;

    get_random_array(arr, size, 257);
    display(arr, size);

    //bogosort(arr, size);
    //bubblesort(arr, size);
	//heapsort(arr, size);
	countsort(arr, size);
    display(arr, size);

    return 0;
}
