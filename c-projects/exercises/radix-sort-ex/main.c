#include <stdio.h>

int initial(int * arr, int size, int digit) {
    int count[10];
    for(int i = 0; i < size; i++) {
        count[(arr[i] / digit) % 10]++;
    }
    
    for(int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    int end[size];
    for(int i = size - 1; i >= 0; i--) {
        end[count[(arr[i] / digit) % 10] - 1] = arr[i];
        count[(arr[i] / digit) % 10]--;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = end[i];
    }
}

void radix_sort(int * arr, unsigned int count) {
    
}

int main(void) {


    return 0;
}