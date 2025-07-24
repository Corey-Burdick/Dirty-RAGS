#include <stdio.h>
#include <iostream>
#include <random>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>

void printArray(std::vector<int> inputArray, bool verbose) {

    if (inputArray.size() <= 10 || verbose) {
        for (int i = 0; i < inputArray.size();) {
            printf("%d", inputArray[i]);
            i++;
            if (i != inputArray.size()) {
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

std::vector<int> generateArray(int size) {
    srand(time(NULL));
    std::vector<int> output(size);
    for (int i = 0; i < size; i++) {
        output[i] = rand() % size + 1;
    }
    return output;
}

void saveArray(std::vector<int> inputArray, std::string filename) {
    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        // File could not be opened. Error Handle.
        std::cerr << "File could not be created or opened." << std::endl;
        return;
    }

    outFile << "Array Size: " << std::endl;
    outFile << inputArray.size() << std::endl;
    
    // Array begins on line 3
    for (int i = 0; i < inputArray.size(); i++) {
        outFile << inputArray[i] << std::endl;
    }

    outFile << "END";

    outFile.close();
}

