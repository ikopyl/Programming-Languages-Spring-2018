#include <stdio.h>
#include "functions.h"

/**
 * Correct way to pass the size of the array is to use sizeof() function
 */
void printIntArray(int *array, unsigned int size) 
{
    genericPrintNumArray(array, size, sizeof(int));
}

void genericPrintNumArray(void *object, unsigned int size, unsigned int elem_size) 
{
    char *p = (char *) object;
    while (p < (char *) object + size) {
        printf("%d\t", *p);
        p += elem_size;
    }
    printf("\n");
}
