#include <stdio.h>
#include "functions.h"

/**
 * Correct way to pass the size of the array is to use sizeof() function
 */
void printCharArray(char *array, unsigned int size)
{
    genericPrintCharArray(array, size, sizeof(char));
}

void printIntArray(int *array, unsigned int size) 
{
    genericPrintNumArray(array, size, sizeof(int));
}

void printUIntArray(unsigned int *array, unsigned int size) 
{
    genericPrintNumArray(array, size, sizeof(int));
}

void genericPrintNumArray(void *object, unsigned int size, unsigned int elem_size) 
{
    char *p = (char *) object;
    while (p < (char *) object + size) {
        printf("%d  ", *p);
        p += elem_size;
    }
    printf("\n");
}

void printCharBitPattern(int n)
{
    int counter = 0;
    while (counter < 8)
    {
        printf("%d  ", (n & 128) == 128 ? 1 : 0);
        n = n << 1;
        counter++;
    }
    printf("\n");
}

void genericPrintCharArray(void *object, unsigned int size, unsigned int elem_size) 
{
    char *p = (char *) object;
    while (p < (char *) object + size) {
        printf("'%c'   ", *p);
        p += elem_size;
    }
    printf("\n");
}

void initializeUIntArray(unsigned int *array, unsigned int size) 
{
    for (int i = 0; i < size; i++)
        array[i] = 0;
}
