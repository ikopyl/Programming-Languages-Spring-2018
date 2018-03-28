#include <stdio.h>
#include "functions.h"

void align(int *, int);

int main()
{

    int s[] = { 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 0, 0, 0 };
    printIntArray(s, sizeof(s));
    align(s, 13);

    return 0;
}

void align(int * s, int n) 
{
    int count = 0;
    while (s[count] == 0)
        count++;
    printf("Index of first non-zero element in the array is %d\n", count);

}
