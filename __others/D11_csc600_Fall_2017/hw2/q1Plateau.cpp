// Nehemya McCarter-Ribakoff
// Dujmovic
// HW2
// 29 September 2017

#include <iostream>

int maxlen(int* a, int n);

int main() {
    int array[14] = {1,1,1,1,2,3,3,4,5,6,6,6,6,7};
    int largestInt = 7;

    std::cout << maxlen(array, largestInt) << "\n";

    return 0;
}

int maxlen(int* a, int n) {
    int longestSequence = 0;
    int currentSequence = 1;
    int lastInt = 0;

    // simple solution:
        // for entire array, as long as lastInt == currentInt,
        // keep incrementing currentSequence.
        // If currentSequence > longestSequence, make them the same.
    for (int index = 0; a[index] < n; index++) {
        if (lastInt == a[index]) {
            ++currentSequence;
            if (currentSequence > longestSequence)
                longestSequence = currentSequence;
        }
        else
            currentSequence = 1;
        lastInt = a[index];
    }
    // optimizations:
        // exit if longestSequence > distance from currentInt to end
    return longestSequence;
}


