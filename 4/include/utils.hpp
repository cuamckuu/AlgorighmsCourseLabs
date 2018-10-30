#ifndef UTILS_HPP
#define UTILS_HPP

#include <cstddef>

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


#endif //UTILS_HPP
