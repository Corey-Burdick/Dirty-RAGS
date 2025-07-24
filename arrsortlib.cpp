#include <stdio.h>
#include <vector>

std::vector<int> bubbleSort(std::vector<int>& inputArray) {
    if (inputArray.size() <= 1) {
        return inputArray;
    }
    for (int i = 0; i < inputArray.size(); i++) {
        for (int j = 0; j < inputArray.size() - 1; j++) {
            if (inputArray[j] > inputArray[j + 1]) {
                int temp = inputArray[j + 1];
                inputArray[j + 1] = inputArray[j];
                inputArray[j] = temp;
            }
        }
    }
    return inputArray;
}

std::vector<int> merge(std::vector<int> leftArray, std::vector<int> rightArray, std::vector<int> inputArray) {
    int i = 0;
    int l = 0;
    int r = 0;
    int leftArraySize = leftArray.size();
    int rightArraySize = rightArray.size();
    int arraySize = inputArray.size();

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

std::vector<int> mergeSort(std::vector<int> inputArray) {
    if (inputArray.size() <= 1) {
        return inputArray;
    }

    int middle = inputArray.size() / 2;
    int leftArraySize = middle;
    int rightArraySize = inputArray.size() - middle;
    std::vector<int> leftArray(middle);
    std::vector<int> rightArray(inputArray.size() - middle);

    int i = 0; // left array
    int j = 0; // right array

    for (; i < inputArray.size(); i++) {
        if (i < middle) {
            leftArray[i] = inputArray[i];
        } else {
            rightArray[j] = inputArray[i];
            j++;
        }
    }

    leftArray = mergeSort(leftArray);
    rightArray = mergeSort(rightArray);
    inputArray = merge(leftArray, rightArray, inputArray);
    return inputArray;

}

bool validateArray(std::vector<int> inputArray) {
    for (int i = 0; i < inputArray.size() - 1; i++) {
        if (inputArray[i] > inputArray[i + 1]) {
            return false;
        }
    }
    return true;
}