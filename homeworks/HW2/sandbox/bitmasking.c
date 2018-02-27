#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{

    unsigned int input, n_bits, *bits, bit;

    // input = 0b0111u;
    // input = 7;
    input = 0b00011000u;
    n_bits = 8u;
    bits = (unsigned int *) malloc(sizeof(unsigned int) * n_bits);
    bit = 0;

    for (bit = 0; bit < n_bits; ++bit)
        bits[bit] = (input >> bit) & 1;
    
    for (bit = n_bits; bit--;)
        //printf("%u", bits[bit]);
        printf("%c", bits[bit] == 1 ? '@' : ' '); 
    printf("\n");

    free(bits);
}
