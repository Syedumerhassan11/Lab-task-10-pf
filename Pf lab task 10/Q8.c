#include <stdio.h>
void printArrayRecursive(int arr[], int size, int index) {
    if (index == size)
        return;
    printf("%d ", arr[index]);
    printArrayRecursive(arr, size, index + 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5}; 
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array elements: ");
    printArrayRecursive(arr, size, 0);

    printf("\n");

    return 0;
}

