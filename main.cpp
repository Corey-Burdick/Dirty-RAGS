#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <chrono>

#include "arrsortlib.h"

// Dirty Random Array Generator and Sorter
// Dirty RAGS
// By: Corey Burdick
// This is a stupid project thrown together as an exercise
// just to get me working with c++ again after a few years
// of inactivity.

int main(int argc, char* argv[]) {

    printf("\n");
    
    // Set initial values.
    int mySize = 5;
    int sortMode = 0;
    bool timerMode = false;
    bool verboseMode = false;

    // Parse array argv to check options. Alter initial values for later use.
    // TODO: This isn't a pretty way of doing this. If statement nesting will
    // make documenting additional functionality a nightmare. Needs cleanup,
    // DESPERATELY.

    if (argc > 1) {
        for (int i = 0; i < argc; i++) {
                
            if (std::string(argv[i]) == "-b") {
                sortMode = 1;
            }

            if (std::string(argv[i]) == "-m") {
                sortMode = 2;
            }

            if (std::string(argv[i]) == "--silly") {
                sortMode = 40;
            }
            
            // TODO: this is bad and dumb code because it does not try/catch to ensure that
            // the user does not attempt to pass bad data. I know that this makes the code
            // unsafe, but I am making this on a bit of a crunch (personal arbitrary deadlines
            // meant to keep me motivated) so haven't made safe for now. At the very least, atoi()
            // always returns 0 if it is passed anything other than an int, so this implementation
            // should work, at least for now.

            if (std::string(argv[i]) == "-c") {
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

            if (std::string(argv[i]) == "-v") {
                verboseMode = true;
            }

		    if (std::string(argv[i]) == "-t") {
			    timerMode = true;
		    }

            if (std::string(argv[i]) == "-h" || std::string(argv[i]) == "--help") {
                printf("Usage: arraystuff [options] ...\n");
                printf("Options:\n");
                printf("\n");
                printf("   -h --help      You are here.\n");
                printf("\n");
                printf("   -v             Verbose Mode. Prints the entire array instead of the first ten elements.\n");
                printf("   -t             Displays the amount of time it takes to generate or sort an array.\n");
                printf("   -c number      Sets the number of elements in the generated array.\n");
                printf("\n");
                printf("                  Sorting Options:\n");
                printf("\n");
                printf("   -b             Sorts the array using Bubble sort.\n");
                printf("   -m             Sorts the array using Merge Sort.\n");
                printf("\n");
                return 0;
            }

        }
    }

    // Main body of the software. Execution time is always tracked, but only displayed
    // if timerMode is enabled from user input.

    auto startTime = std::chrono::high_resolution_clock::now();
    int* myArray = generateArray(mySize);
    printArray(myArray, mySize, verboseMode);
    auto endTime = std::chrono::high_resolution_clock::now();

    if (timerMode == true) {
	auto trackedTime = std::chrono::duration_cast<std::chrono::milliseconds>(startTime - endTime);
        long long duration = trackedTime.count();
	printf("Generation time: %lldms\n", duration);
    }

    // Sorts the generated array using the sort mode with mild error handling if 
    // somehow the sort mode value gets out of scope.

    startTime = std::chrono::high_resolution_clock::now();

    bool valid = false;
    
    switch(sortMode) {
        case 0:
            printf("Array not sorted\n");
            break;
        case 1:
            myArray = bubbleSort(myArray, mySize);
            valid = validateArray(myArray, mySize);
            endTime = std::chrono::high_resolution_clock::now();
            printArray(myArray, mySize, verboseMode);
            break;
        case 2:
            myArray = mergeSort(myArray, mySize);
            valid = validateArray(myArray, mySize);
            endTime = std::chrono::high_resolution_clock::now();
            printArray(myArray, mySize, verboseMode);
            break;
        default:
            printf("Kris, how the hell did we get here?\n");
            return 0;
    }

    if (timerMode == true && sortMode != 0) {
    	auto trackedTime = std::chrono::duration_cast<std::chrono::milliseconds>(startTime - endTime);
        long long duration = trackedTime.count();
        printf("Sort time: %lldms\n", duration);
    }

    if (valid && sortMode != 0) {
        printf("Sort has been validated.\n");
    } else if (sortMode != 0) {
        printf("Sort could not be validated.\n");
    }

    printf("\n");
    // Deallocate the memory on the heap
    delete[] myArray;
    myArray = nullptr;
    
    return 0;
}
