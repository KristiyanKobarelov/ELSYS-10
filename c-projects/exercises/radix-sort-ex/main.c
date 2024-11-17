#include <stdio.h>

int get_max(int arr[], int size) {
    int max = arr[0];
    for(int i = 0; i < size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int count_sort(int arr[], int size, int digit) {
    int count[10] = {0};
    for(int i = 0; i < size; i++) {
        count[(arr[i] / digit) % 10]++;
    }
    
    for(int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    int output[size];
    for(int i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / digit) % 10] - 1] = arr[i];
        count[(arr[i] / digit) % 10]--;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

void radix_sort_recursive(int arr[], int size, int digit, int maxVal) {
    if (maxVal / digit > 0) {
        count_sort(arr, size, digit);
        radix_sort_recursive(arr, size, digit * 10, maxVal);
    }
}

void radixsort(int arr[], int size) {
    int max = get_max(arr, size);
    radix_sort_recursive(arr, size, 1, max);
}

void print(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

int main(void) {
    int arr1[] = {170, 45, 75, 90, 802, 24, 2, 66, 5687}; // Не работи с отрицателни стойности :_(
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Original array:\n");
    print(arr1, size1);
    radixsort(arr1, size1);
    printf("\nSorted array:\n");
    print(arr1, size1);

    int arr2[] = {1, 3, 5, 2, 6, 4, 9};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("\nOriginal array:\n");
    print(arr2, size2);
    radixsort(arr2, size2);
    printf("\nSorted array:\n");
    print(arr2, size2);

    int arr3[] = {520, 6245, 45, 87564, 100, 0, 15};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("\nOriginal array:\n");
    print(arr3, size3);
    radixsort(arr3, size3);
    printf("\nSorted array:\n");
    print(arr3, size3);
    
    int arr4[] = {121, 11, 51, 21, 31, 1521};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    printf("\nOriginal array:\n");
    print(arr4, size4);
    radixsort(arr4, size4);
    printf("\nSorted array:\n");
    print(arr4, size4);

    return 0;
}