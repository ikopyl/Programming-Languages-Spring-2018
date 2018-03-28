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
