// Nehemya McCarter-Ribakoff
// Dujmovic
// HW2
// 29 September 2017

#include <iostream>
#include <limits.h>
#include <vector>

void findThreeLargest(int numberList[], int topThree[]);
void reduce(int numberList[], int arLength);
void printArray(int numberList[]);
int arrayLength(int numberList[]);

int main() {
int sampleList[] = {1,2,2,3,3,3,4,4,4,4,5,5,5,5,5,7,3,2,4,7,1,3,2,9,2,1,3,4,4,'\0'};

std::endl << "PROBLEM 3)\n" << std::endl;

std::cout <<"Original array: \n";
printArray(sampleList);

reduce(sampleList, sizeof(sampleList)/sizeof(sampleList[0]));

std::cout <<"Reduced array: \n";
printArray(sampleList);
    return 0;
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
