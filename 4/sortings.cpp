#include "include/sortings.h"

void shuffle(int *arr, size_t size) {
    for (size_t i = size-1; i > 0; i--) {
        size_t j = rand() % (i+1);
        std::swap(arr[i], arr[j]);
    }
}

int partition(int *arr, int low, int high) {
	//Lomuto's partition

    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
			std::swap(arr[i], arr[j]);
            i++;
        }
    }

	std::swap(arr[i], arr[high]);
    return i;
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
    int arr_cnt[260] = {0}; // Some extra space to prevent errors
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

int binsearch(int *arr, int l, int r, int key) {
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

void __quicksort(int *arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);

        __quicksort(arr, low, p - 1);
        __quicksort(arr, p + 1, high);
    }
}

void quicksort(int *arr, size_t size) {
	shuffle(arr, size);
	__quicksort(arr, 0, size-1);
}
