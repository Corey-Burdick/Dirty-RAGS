#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <chrono>
#include <fstream>

#include "arrsortlib.h"
#include "ragsiolib.h"

// Dirty Random Array Generator and Sorter
// Dirty RAGS
// By: Corey Burdick
// This is a stupid project thrown together as an exercise
// just to get me working with c++ again after a few years
// of inactivity.



int main(int argc, char* argv[]) {

    
    // Set initial values.
    std::string versionNumber = "0.3.01";
    int mySize = 5;
    int sortMode = 0;
    bool validSort = false;
    bool timerMode = false;
    bool verboseMode = false;
    bool readMode = false;
    bool writeMode = false;
    std::string filename = "output.txt";

    // Parse array argv to check options. Alter initial values for later use.

    if (argc > 1) {
        for (int i = 0; i < argc; i++) {
            std::string arg = argv[i];

            if (arg == "--version") {
                printf("Dirty RAGS version: %s\n", versionNumber.c_str());
                return 0;
            }

            if (arg == "-s" || arg == "--save") {
                writeMode = true;
            }

            if (arg == "-b" || arg == "--bubbleSort") {
                sortMode = 1;
            }

            if (arg == "-m" || arg == "--mergeSort") {
                sortMode = 2;
            }

            if (arg == "-n" || arg == "--number") {
                mySize = atoi(argv[i + 1]);
                if (mySize > 1000000) {
                    printf("RAGS has a hard limit of 1000000 elements to prevent overallocation.\n");
                    printf("\n");
                    return 0;
                }
                if (mySize <= 0) {
                    printf("Option \"-c\" requires an a postitive integer.\n");
                    printf("\n");
                    return 0;
                }
            }

            if (arg == "-v" || arg == "--verbose") {
                verboseMode = true;
            }

		    if (arg == "-t" || arg == "--time") {
			    timerMode = true;
		    }

            if (arg == "-h" || arg == "--help") {
                printf("Usage: arraystuff [options] ...                                                           \n");
                printf("Options:                                                                                  \n");
                printf("                                                                                          \n");
                printf("   --version      Show version number.                                                    \n");
                printf("   -h                                                                                     \n");
                printf("   --help         You are here.                                                           \n");
                printf("                                                                                          \n");
                printf("   -s                                                                                     \n");
                printf("   --save         Saves the generated array to 'output.txt'                               \n");
                printf("   -v                                                                                     \n");
                printf("   --verbose      Verbose Mode. Prints the entire array instead of the first ten elements.\n");
                printf("   -t             Displays the amount of time it takes to generate or sort an array.      \n");
                printf("   -n [number]    Sets the number of elements in the generated array.                     \n");
                printf("                                                                                          \n");
                printf("                  Sorting Options:                                                        \n");
                printf("                                                                                          \n");
                printf("   -b             Sorts the array using Bubble sort.                                      \n");
                printf("   -m             Sorts the array using Merge Sort.                                       \n");
                printf("                                                                                          \n");
                return 0;
            }

        }
    }

    // Main body of the software.

    auto startTime = std::chrono::high_resolution_clock::now();
    
    std::vector<int> myArray = generateArray(mySize);
    printf("Generated Random Array: ");
    printArray(myArray, verboseMode);

    auto endTime = std::chrono::high_resolution_clock::now();

    if (timerMode) {
	auto trackedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
        long long duration = trackedTime.count();
	printf("Generation time: %lldms\n", duration);
    }

    // Sorts the generated array using the sort mode with mild error handling if 
    // somehow the sort mode value gets out of scope.

    startTime = std::chrono::high_resolution_clock::now();
    
    switch(sortMode) {
        case 0:
            printf("Array not sorted\n");
            break;
        case 1:
            myArray = bubbleSort(myArray);
            validSort = validateArray(myArray);
            endTime = std::chrono::high_resolution_clock::now();
            break;
        case 2:
            myArray = mergeSort(myArray);
            validSort = validateArray(myArray);
            endTime = std::chrono::high_resolution_clock::now();
            break;
        default:
            printf("Kris, how the hell did we get here?\n");
            return 0;
    }
    
    if (sortMode != 0) { 
        printf("Sorted Random Array: ");
        printArray(myArray, verboseMode);
    }

    if (timerMode == true && sortMode != 0) {
    	auto trackedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
        long long duration = trackedTime.count();
        printf("Sort time: %lldms\n", duration);
    }

    if (validSort && sortMode != 0) {
        printf("Sort has been validated.\n");
    } else if (sortMode != 0) {
        printf("Sort could not be validated.\n");
    }
    
    if (writeMode) saveArray(myArray, filename);

    return 0;
}
