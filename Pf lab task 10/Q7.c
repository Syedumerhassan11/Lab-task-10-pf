#include <stdio.h>
void bubbleSortRecursive(int arr[], int size) {
    if (size == 1)
        return;
        int i=0;
    for (; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    bubbleSortRecursive(arr, size - 1);
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    int i=0;
	for (; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    bubbleSortRecursive(arr, size);
int i; // Declare 'i' outside the loop
printf("Sorted array: ");
for (i = 0; i < size; i++) // Use 'i' here
    printf("%d ", arr[i]);
printf("\n");
return 0;
}
  


