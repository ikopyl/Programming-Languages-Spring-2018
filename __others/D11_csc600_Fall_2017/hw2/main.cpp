// Nehemya McCarter-Ribakoff
// Dujmovic
// HW2
// 29 September 2017

#include <iostream>
#include <limits.h>
#include <vector>

// for question 1
int maxlen(int* a, int n);

// for question 3
void findThreeLargest(int numberList[], int topThree[]);
void reduce(int numberList[], int arLength);
void printArray(int numberList[]);
int arrayLength(int numberList[]);

// for question 4
void bigInt(int);


int main() {

    std::cout << "QUESTION 1:\n";

    int array[14] = {1,1,1,2,3,4,5,5,6,6,6,6,7, '\0'};
    int largestInt = 7;

    std::cout << "Array: ";
    printArray(array);

    std::cout << "Longest series: " << maxlen(array, largestInt) << "\n";

    std::cout << "QUESTION 3:\n";

    int sampleList[] = {1,2,2,3,3,3,4,4,4,4,5,5,5,5,5,7,3,2,4,7,1,3,2,9,2,1,3,4,4,'\0'};

    std::cout <<"Original array: \n";
    printArray(sampleList);

    reduce(sampleList, sizeof(sampleList)/sizeof(sampleList[0]));

    std::cout <<"Reduced array: \n";
    printArray(sampleList);

    std::cout << "QUESTION 4:\n";

    int inputNumber = 192037;

    std::cout << "Input number: " << inputNumber << "\n";
    bigInt(inputNumber);

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

void findThreeLargest(int numberList[], int topThree[]){

    int arLength = arrayLength(numberList);

    for (int index = 0; index < arLength; index++) {
        /* we compare to the 3rd largest value first
           to save comparisons if the value is small */
        if (numberList[index] > topThree[2] && numberList[index] != topThree[1] 
            && numberList[index] != topThree[0]) {
            if (numberList[index] > topThree[1]) {
                if (numberList[index] > topThree[0]) {
                    /* numberList[index] is the largest */
                    topThree[2] = topThree[1];
                    topThree[1] = topThree[0];
                    topThree[0] = numberList[index];
                } else {
                    /* numberList[index] is the second largest */
                    topThree[2] = topThree[1];
                    topThree[1] = numberList[index];
                }
            } else {
                /* numberList[index] is the third largest */
                topThree[2] = numberList[index];
            }
        }
    }
}

void reduce(int numberList[], int arLength){
    int topThreeValues[3] = {INT_MIN, INT_MIN, INT_MIN};
    int j = 0;

    findThreeLargest(numberList, topThreeValues);
    /* check if array contains at least
       three values                    */
    if (arLength <= 3) {
        /* we end each array with a null terminator
           for bounds checking */
        numberList[0] = '\0';
    } else {
        for(int index = 0; index < arLength; index++) {
            if(!(topThreeValues[0] == numberList[index] || topThreeValues[1] == numberList[index] ||
               topThreeValues[2] == numberList[index])) {

                numberList[j] = numberList[index];
                j++;
            }
        }

        numberList[j] = '\0';
    }
}

void printArray(int numberList[]){
    for(int index = 0; index < arrayLength(numberList); index++)
        std::cout << numberList[index] << " ";
    std::cout << "\n\n";
}

int arrayLength(int numberList[]){
    int index = 0;
    while(numberList[index] != '\0')
        index++;
    return index;
}

void bigInt(int n) {
    std::string digits[7][10] = {
    {" @@@@@ ", "   @@  ", "@@@@@@@", "@@@@@@@", "@@   @@", "@@@@@@@", 
     "     @@", "@@@@@@@", " @@@@@ ", " @@@@@ "},

    {"@@   @@", "  @@@  ", "     @@", "     @@", "@@   @@", "@@    ", 
     "   @@  ", "     @@", "@@   @@", "@@   @@"},

    {"@@   @@", "   @@  ", "    @@ ", "     @@", "@@   @@", "  @@   ", 
     " @@    ", "    @@ ", "@@   @@", "@@   @@"},

    {"@@   @@", "   @@  ", " @@    ", "  @@@@@", "@@@@@@@", "    @@ ", 
     "@@@@@@@", "   @@  ", "@@@@@@@", "@@@@@@@"},

    {"@@   @@", "   @@  ", "@@     ", "     @@", "     @@", "     @@", 
     "@     @", "  @@   ","@@   @@", "    @@ "},

    {"@@   @@", "   @@  ", "@@     ", "     @@", "     @@", "     @@", 
     "@     @", " @@    ", "@@   @@", "    @@ "},

    {" @@@@@ ", "@@@@@@@", "@@@@@@@", "@@@@@@@", "     @@", "@@@@@@ ", 
     "@@@@@@@" , "@@     ", " @@@@@ ", " @@@   "}

    };

    int numberArray[256]; // to store individual digits of input value
    int numberOfDigits = 0;
    std::string printString = "";

    while (n) {
        numberArray[numberOfDigits++] = n % 10; // assigns leftmost digit
        n /= 10; // remove leftmost digit
    }


    for (int index = 0; index < 7; index++) {
        for (int digit = numberOfDigits - 1; digit >= 0 ; digit--) {
            printString += digits[index][numberArray[digit]];
            printString += "   ";
        }
        std::cout << printString << "\n";
        printString = "\0";
    }
}

