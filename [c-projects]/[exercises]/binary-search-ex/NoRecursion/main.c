#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int size;
    printf("Enter size of the array: \n");
    scanf("%d", &size);

    int arr[size];
    for(int i = 0; i < size; i++) {
        printf("Enter value: \n");
        scanf("%d", &arr[i]);
    }

    int value;
    printf("\nEnter THE value: \n");
    scanf("%d", &value);

    int l = 0;
    int r = size - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if(arr[mid] == value) {
            printf("The value is: %d", arr[mid]);
            exit(0);
        }

        if(arr[mid] < value) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }


    return 0;
}