#include <stdio.h>
#include <stdlib.h>

void selectionsort(int * arr, int n) {
    int min, tmp;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = arr[i];
    }

    return;
}

int main(void) {
    int arr[5] = {2, 5, 3, 4, 1};
    selectionsort(arr, 5);
    for(int i = 0; i < 5; i++) {
        printf("%d, ", arr[i]);
    }

    return 0;
}


