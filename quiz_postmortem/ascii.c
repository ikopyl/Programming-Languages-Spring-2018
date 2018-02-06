#include <stdio.h>

int main()
{

    unsigned char c1 = '4' * 5;         // warning: implicit conversion from 'int' to 'unsigned char' changes value from 260 to 4
    signed char c2 = '4' * 5;           // warning: implicit conversion from 'int' to 'signed char' changes value from 260 to 4

    printf("unsigned char c1 = '4' * 5 == \t%d\n", c1);
    printf("signed char c2 = '4' * 5 == \t%d\n", c2);

    puts("------------------");

    c1 = 'A' + 'C';
    c2 = 'A' + 'C';

    printf("unsigned char c1 = 'A' + 'C' == %d\n", c1);
    printf("signed char c2 = 'A' + 'C' == \t%d\n", c2);

    puts("------------------");

    printf("('A' + 'C') / 66 == 2 ? %s\n", 
            ('A' + 'C') / 66 == 2 ? "Correct" : "Incorrect");

    puts("------------------");

    float f = 1./3.;
    double d = 1./3.;

    printf("1./3. == f ? %s\n", 
            1./3. == f ? "Correct" : "Incorrect");
    printf("1./3. == d ? %s\n",
            1./3. == d ? "Correct" : "Incorrect");

    return 0;
}
