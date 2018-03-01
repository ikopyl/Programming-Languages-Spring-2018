#include <stdio.h>
#include <math.h>
#include "functions.h"

void initializeArray(int *, int);

int main() 
{

    printf("%f\n", log2(9));
    printf("%d\n", (unsigned int) log2(9));         // floor of log2(9)

    int sizeOfArray = 10;
    int a[sizeOfArray];
    initializeArray(a, sizeOfArray);
    printIntArray(a, sizeof(a));



    return 0;
}

void initializeArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
        a[i] = i;
}
