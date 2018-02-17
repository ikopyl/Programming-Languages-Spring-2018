#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

// The iterative binary search method
int binarySearch(int a[], int n, int x) {
    
    int min = 0;
    int max = (n - 1);
    int mid;
    while (min <= max) 
    {
        mid = min + ((max - min)/2);
        if (a[mid] < x) 
            min = mid + 1;
         else if (a[mid] > x)
            max = mid - 1;
         else 
            return mid;
    }
    return 0;
}

// The recursive binary search method
int RecursiveBS(int a[], int n, int x, int min, int max) {
    
    int mid;
    if (min <= max) 
    {
        mid = (max + min)/2;
        if (a[mid] < x) 
            return RecursiveBS(a, n, x, mid + 1, max);
         else if (a[mid] > x) 
            return RecursiveBS(a, n, x, min, mid - 1);
         else 
            return mid;
    }else 
    return 0;
}

int main(void) {
    // initialize array size and the number of times the binary search will run.
    int n = 75000, K = 150;
    int a[n];
    //Filling the array in a sorted manner
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
    clock_t start, finish;
    
    // test iterative binary search
    start = clock();
    for (int j = 0; j < n; j++) 
    {
        for (int i = 0; i < K; i++) 
        {
            if (binarySearch(a, n, i) != i) 
                cout << "\nERROR" << endl;
        }
    }
    //capture clock time
    finish = clock();
    //print the iterative method executiontime and subtracting possible start time error.
    cout << "Iterative: " << (double) (finish - start) / CLOCKS_PER_SEC << " sec." << endl;
    
    start = clock();
    for (int j = 0; j < K; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (RecursiveBS(a, n, i, 0, n - 1) != i)
                cout << "\nERROR" << endl;
        }
    }
    finish = clock();
    //print the recursive method executiontime and subtracting possible start time error.
    cout << "Recursive: " << (double) (finish - start) / CLOCKS_PER_SEC << " sec." << endl;
    
    return 0;
}
