#include <stdio.h>
#include <stdlib.h>

int sum(int);

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
int sum(int n)
{
    int currentDigit = 0;
    do {
        currentDigit += n % 10;
    } while ((n /= 10) != 0);

    return abs(currentDigit);
}
