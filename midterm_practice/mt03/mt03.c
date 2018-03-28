#include <stdio.h>
#include "functions.h"

void align(char *, int);

int main()
{

    puts("");

    char s[] = { ' ', ' ', ' ', ' ', ' ', ' ', 'f', 'i', 'r', 's', 't', ' ', ' ', ' ', ' ', 'l', 'a', 's', 't', '\0', ' ', ' ', ' ', ' ' };
    printCharArray(s, sizeof(s));
    align(s, 24);

    puts("");

    char s1[] = { ' ', ' ', 'f', 'i', 'r', 's', 't', ' ', ' ', ' ' };
    printCharArray(s1, sizeof(s1));
    align(s1, 10);

    puts("");

    char s2[] = { ' ', ' ', 'f', 'i', 'r', 's', 't', '\0', ' ', ' ' };
    printCharArray(s2, sizeof(s2));
    align(s2, 10);

    puts("");

    char s3[] = { ' ', ' ', 'f', 'i', 'r', 's', 't', ' ', ' ', '\0' };
    printCharArray(s3, sizeof(s3));
    align(s3, 10);

    puts("");

    return 0;
}

void align(char * s, int n) 
{
    int count = 0;
    while (s[count] == 0)
        count++;
    printf("First non-zero element index: %d\n", count);

    for (int i = 0; i < n; i++, count++) 
    {
        s[i] = s[count];
        if (s[count] == EOF || count >= n) 
        {
            printf("Index of EOF: %d\n", count);
            count++;
            break;
        }
    }

}
