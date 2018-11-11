#include "include/sortings.h"

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

void countsort(char *arr, size_t size) {
    int arr_cnt[260] = {0}; // Some extra space to prevent error
	int *counter = &arr_cnt[128];

	for (size_t i = 0; i < size; i++) {
		counter[arr[i]]++;
	}

	size_t cnt = 0;
	for (int i = -127; i < 127; i++) {
		for (int j = 0; j < counter[i]; j++) {
			arr[cnt] = i;
			cnt++;
		}
	}
}

size_t binsearch(int *arr, size_t l, size_t r, int key) {
   if (r >= l) {
        size_t mid = l + (r - l) / 2;

        if (arr[mid] == key) {
            return mid;
		}

        if (arr[mid] > key) {
            return binsearch(arr, l, mid-1, key);
		}

        return binsearch(arr, mid+1, r, key);
   }

   return -1;
}

size_t binsearch(char *arr, size_t l, size_t r, char key) {
   if (r >= l) {
        size_t mid = l + (r - l) / 2;

        if (arr[mid] == key) {
            return mid;
		}

        if (arr[mid] > key) {
            return binsearch(arr, l, mid-1, key);
		}

        return binsearch(arr, mid+1, r, key);
   }

   return -1;
}

void quicksort(int *arr, size_t size) {

}
