#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *arr, int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void printArray(int *arr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
  int arr[] = {9, -3, 4, 200, 2, 78, 5, 10, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Matriz original: ");
    printArray(arr, size);

    bubbleSort(arr, size);

    printf("Matriz ordenada: ");
    printArray(arr, size);

    return 0;
	
	
	
	return 0;
}