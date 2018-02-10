#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

unsigned int sum(int);
short allDifferent(unsigned int[], unsigned int);

int main() {

    printf("sum(654321) == 21 ? %s\n",
            sum(654321) == 21 ? "True" : "False");

    printf("sum(-654321) = %d\n\n", 
            sum(-654321));


    unsigned int a[5] = { 17, 22, 33, 41, 9 };
    printUIntArray(a, sizeof(a));
    puts("");

    short trueOrFalse = allDifferent(a, 5);
    puts("");

    printf("allDifferent(a, 5) == 1 ? %s\n",
            trueOrFalse == 1 ? "True" : "False");
    printf("allDifferent(a, 5) =  %d\n", 
            trueOrFalse);


    return 0;
}

/**
 * A function that returns the sum of digits of a positive integer n
 */
unsigned int sum(int n)
{
    unsigned int sumOfDigits = 0;
    do {
        sumOfDigits += n % 10;
    } while ((n /= 10) != 0);
    
    printf("sumOfDigits = %d\n", sumOfDigits);
    return abs(sumOfDigits);
}

short allDifferent(unsigned int *a, unsigned int na) {

    unsigned int sumsOfDigits[na];
    initializeUIntArray(sumsOfDigits, na);
    // number of comparisons would increase per each iteration
    int temp;

    for (int i = 0; i < na; i++) {
        printf("Current number: %d, ", a[i]);
        temp = sum(a[i]);
        if (i > 0)
            for (int j = 0; j < i; j++)             // sequential search for now - assuming non sorted array
                if (sumsOfDigits[j] == temp)
                    return 0;

        sumsOfDigits[i] = temp;             // should do mergesort insert && binary search
        printUIntArray(sumsOfDigits, sizeof(sumsOfDigits));
    }

    return 1;
}
