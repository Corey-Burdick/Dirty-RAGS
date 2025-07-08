#include <stdio.h>
#include <iostream>
#include <random>
#include <ctime>
#include <fstream>
#include <string>

void printArray(int inputArray[], int arraySize, bool verbose) {
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
}

int* generateArray(int size) {
    srand(time(NULL));
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % size + 1;
    }
    return arr;
}

void saveArray(int inputArray[], int arraySize, std::string filename) {
    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        // File could not be opened. Error Handle.
        std::cerr << "File could not be created or opened." << std::endl;
        return;
    }

    outFile << "Array Size: " << std::endl;
    outFile << arraySize << std::endl;
    
    // Array begins on line 3
    for (int i = 0; i < arraySize; i++) {
        outFile << inputArray[i] << std::endl;
    }

    outFile << "END";

    outFile.close();
}

