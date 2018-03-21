#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

unsigned int sum(int);
short allDifferent(unsigned int[], unsigned int);

int main() {

    short trueOrFalse = 0;

    unsigned int a[5] = { 17, 22, 33, 41, 9 };
    printUIntArray(a, sizeof(a));
    trueOrFalse = allDifferent(a, 5);
    printf("allDifferent(a, 5) ? %s\n",
            trueOrFalse == 1 ? "True" : "False");
    puts("");

    unsigned int b[5] = { 17, 22, 33, 42, 9 };
    printUIntArray(b, sizeof(b));
    trueOrFalse = allDifferent(b, 5);
    printf("allDifferent(a, 6) ? %s\n",
            trueOrFalse == 1 ? "True" : "False");
    puts("");

    return 0;
}

/**
 * A function that returns the sum of digits of a positive integer n
 */
unsigned int sum(int n)
{
    unsigned int sumOfDigits = 0;
    do
        sumOfDigits += n % 10;
    while (n /= 10);
    
    return abs(sumOfDigits);
}

/**
 * A function that return 1 if all components of the positive integer array 
 * a[0..na-1] have different sums of digits; otherwise it returns 0.
 */
short allDifferent(unsigned int *a, unsigned int na)
{
    unsigned int sums[na];
    for (int i = 0; i < na; i++)
        sums[i] = sum(a[i]);

    printIntArray(sums, sizeof(sums));

    for (int i = 0; i < na - 1; i++)
        for (int j = i + 1; j < na; j++)
            if (sums[i] == sums[j])
                return 0;

    return 1;
}
