#include <stdio.h>

int maxlen(int*, unsigned int);

int main()
{

    return 0;
}

int maxlen(int* a, unsigned int n)
{
    unsigned int max_count, current_count, i;
    max_count = 0;
    current_count = 1;

    for (i = 1; i < n; i++) 
    {
        if (a[i] == a[i-1])
            current_count++;
        else if (current_count > max_count)
            max_count = current_count;
        else
            current_count = 1;
    }
    return max_count;
}
