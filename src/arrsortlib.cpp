#include <stdio.h>
#include <random>
#include <ctime>

void printArray(int inputArray[], int arraySize) {
    printf("Printed Array: ");
    for (int i = 0; i < arraySize;) {
        printf("%d",inputArray[i]);
        i++;
        if (i != arraySize) {
            printf(", ");
        }
    }
    printf("\n");
}

int* generateArray(int size) {
    srand(time(NULL));
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % size + 1;
    }
    return arr;
}

int* bubbleSort(int inputArray[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        for (int j = 0; j < arraySize - 1; j++) {
            if (inputArray[j] > inputArray[j + 1]) {
                int temp = inputArray[j + 1];
                inputArray[j + 1] = inputArray[j];
                inputArray[j] = temp;
            }
        }
    }
    return inputArray;
}