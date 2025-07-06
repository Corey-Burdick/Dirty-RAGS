#include <stdio.h>
#include <random>
#include <ctime>

void printArray(int inputArray[], int arraySize, bool verbose) {
    printf("\n");
    printf("Printed Array: ");

    if (arraySize <= 10 || verbose) {
        for (int i = 0; i < arraySize;) {
            printf("%d", inputArray[i]);
            i++;
            if (i != arraySize) {
                printf(", ");
            }
        }
        printf("\n");
    } else {
        for (int i = 0; i < 10;) {
            printf("%d", inputArray[i]);
            i++;
            if (i != 10) {
                printf(", ");
            }
        }
        printf("...\n");
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