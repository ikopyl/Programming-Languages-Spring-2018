#include <stdio.h>

int main()
{
    int n=1;
    for (;;++n) {
        int msb;
        asm("bsrl %1,%0" : "=r"(msb) : "r"(n));
        printf("n = %d : %d\n", msb, n);
    }
    return 0;
}
