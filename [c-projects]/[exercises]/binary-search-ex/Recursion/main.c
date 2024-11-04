#include <stdio.h>

int binarysearch(int l, int r, int arr[], int search) {
    int mid = l + (r - l) / 2;
    if(arr[mid] == search) {
        return mid;
    }

    if(arr[mid] < search) {
        l = mid + 1;
    } else {
        r = mid - 1;
    }

    if(l <= r) {
        return binarysearch(l, r, arr, search);
    }

    return -1;

}

int main(void) {
    int arr[5] = {1, 2, 3, 4, 5};

    int search = 4;

    int result = binarysearch(0, 4, arr, search);

    if(result != -1) {
        printf("Found at %d!", result);
    } else {
        printf("Not found ;(");
    }

    return 0;
}