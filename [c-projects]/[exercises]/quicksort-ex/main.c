#include <stdio.h>

int quicksortpart(int arr[], int l, int r) {
    int pivot = arr[(l + r) / 2];

    while (1) {
        while (arr[l] < pivot) {
            l++;
        }

        while (arr[r] > pivot) {
            r--;
        }

        if(l >= r) {
            return r;
        }

        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
    }
}

void quicksort(int arr[], int l, int r) {
    if (l <= r) {
        int mid = quicksortpart(arr, l, r);
        quicksort(arr, l, mid - 1);
        quicksort(arr, mid + 1, r);
    }
}

int main(void) {
    int arr[5] = {1, 3, 5, 4, 2};
    int size = 5;

    quicksort(arr, 0, size - 1);

    for(int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}