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

int* bubbleSort(int inputArray[], int arraySize) {
    if (arraySize <= 1) {
        return inputArray;
    }
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

int* merge(int leftArray[], int leftArraySize, int rightArray[], int rightArraySize, int inputArray[], int arraySize) {
    int i = 0;
    int l = 0;
    int r = 0;

    while (l < leftArraySize && r < rightArraySize) {
        if (leftArray[l] < rightArray[r]) {
            inputArray[i] = leftArray[l];
            i++;
            l++;
        } else {
            inputArray[i] = rightArray[r];
            i++;
            r++;
        }
    }
    while (l < leftArraySize) {
        inputArray[i] = leftArray[l];
        i++;
        l++;
    }
    while (r < rightArray[r]) {
        inputArray[i] = rightArray[r];
        i++;
        r++;
    }

    return inputArray;
}

int* mergeSort(int inputArray[], int arraySize) {
    if (arraySize <= 1) {
        return inputArray;
    }

    int middle = arraySize / 2;
    int leftArraySize = middle;
    int rightArraySize = arraySize - middle;
    int* leftArray = new int[middle];
    int* rightArray = new int[arraySize - middle];

    int i = 0; // left array
    int j = 0; // right array

    for (; i < arraySize; i++) {
        if (i < middle) {
            leftArray[i] = inputArray[i];
        } else {
            rightArray[j] = inputArray[i];
            j++;
        }
    }

    leftArray = mergeSort(leftArray, leftArraySize);
    rightArray = mergeSort(rightArray, rightArraySize);
    inputArray = merge(leftArray, leftArraySize, rightArray, rightArraySize, inputArray, arraySize);
    return inputArray;

}

bool validateArray(int inputArray[], int arraySize) {
    for (int i = 0; i < arraySize - 1; i++) {
        if (inputArray[i] > inputArray[i + 1]) {
            return false;
        }
    }
    return true;
    
}