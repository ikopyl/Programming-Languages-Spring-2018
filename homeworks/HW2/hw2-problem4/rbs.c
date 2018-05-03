#include <stdio.h>

int recursiveBinarySearch(int *, int, int);

int main()
{
    int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    for (int i = 0; i < 10; i++)
        if (recursiveBinarySearch(a, 10, i) != i) {
            puts("ERROR:");
            printf("a[%d] = %d,\trbs = %d\n", 
                    i, a[i], recursiveBinarySearch(a, 10, i));
        }

    return 0;
}

int recursiveBinarySearch(int *a, int n, int value)
{
    int mid = n / 2;

    if (a[mid] == value)
        return mid;
    else if (a[mid] > value)
        return recursiveBinarySearch(a, value, mid);
    else if (a[mid] < value)
        return recursiveBinarySearch(&a[mid], value, n-mid);
    return -1;
}


// for reference only:

//int bin(int a*, int value, int size)
//{
//    int mid = size / 2;
//    
//    if (a[mid] > value)
//        return bin(a, value, mid);
//    else if (array[mid] < value)
//        return bin(&a[mid], value, size-mid);
//    else
//        return mid;
//}
//
