#include <stdio.h>
#include <stdlib.h>

unsigned int sum(int);
short allDifferent(unsigned int[], unsigned int);

int main() {

    printf("sum(654321) == 21 ? %s\n",
            sum(654321) == 21 ? "True" : "False");

    printf("sum(-654321) = %d\n", 
            sum(-654321));


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
        printf("sumOfDigits = %d\n", sumOfDigits);
    } while ((n /= 10) != 0);

    return abs(sumOfDigits);
}

short allDifferent(unsigned int a[], unsigned int na) {

    unsigned int sumsOfDigits[na];
    // number of comparisons would increase per each iteration
    for (int i = 0; i < na; i++) {

    }

    return 1;
}
