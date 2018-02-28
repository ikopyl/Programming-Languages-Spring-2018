#include <stdio.h>
#include <math.h>
#include "functions.h"

void BigInt(unsigned int);

unsigned int getNumberOfDigits(unsigned int);


/**
 * Digits are stored as bit patterns of 8-bit unsigned integer (char) numbers.
 *
 * Each digit requires just 8 bytes of storage - which is polynomially smaller
 * than the storage in brute-force approach where each digit is represented by
 * a 2D array of 8x8 characters, with 64 bytes of storage per digit.
 */
#define NUMBER_OF_ROWS 8

const unsigned char digits[NUMBER_OF_ROWS][10] = {

        {       // row 0 of all 10 digits
                0b00000000u, 0b00000000u, 0b00000000u, 0b00000000u, 0b00000000u,
                0b00000000u, 0b00000000u, 0b00000000u, 0b00000000u, 0b00000000u
        },

        {       // row 1 of all 10 digits
                0b00111110u, 0b00001100u, 0b00011110u, 0b00011110u, 0b00000110u,
                0b00111111u, 0b00011110u, 0b01111111u, 0b00011110u, 0b00011110u
        },

        {       // row 2 of all 10 digits
                0b01100011u, 0b00011100u, 0b00110011u, 0b00110011u, 0b00001110u,
                0b00110000u, 0b00110011u, 0b00000011u, 0b00110011u, 0b00110011u
        },

        {       // row 3 of all 10 digits
                0b01100011u, 0b00001100u, 0b00110011u, 0b00000011u, 0b00010110u,
                0b00110000u, 0b00110000u, 0b00000110u, 0b00110011u, 0b00110011u
        },

        {       // row 4 of all 10 digits
                0b01100011u, 0b00001100u, 0b00000110u, 0b00001100u, 0b00110110u,
                0b00111110u, 0b00111110u, 0b00001100u, 0b00011110u, 0b00011111u
        },

        {       // row 5 of all 10 digits
                0b01100011u, 0b00001100u, 0b00001100u, 0b00000011u, 0b01100110u,
                0b00000011u, 0b00110011u, 0b00011000u, 0b00110011u, 0b00000011u
        },

        {       // row 6 of all 10 digits
                0b01100011u, 0b00001100u, 0b00011000u, 0b00110011u, 0b01111111u,
                0b00000011u, 0b00110011u, 0b00110000u, 0b00110011u, 0b00110011u
        },

        {       // row 7 of all 10 digits
                0b00111110u, 0b00111111u, 0b00111111u, 0b00011110u, 0b00000110u,
                0b00111110u, 0b00011110u, 0b01100000u, 0b00011110u, 0b00011110u
        }
};

int main()
{
    printf("%d has %d digits\n", 170, getNumberOfDigits(170));
    printf("%d has %d digits\n", 123, getNumberOfDigits(123));
    printf("%d has %d digits\n", 17, getNumberOfDigits(17));

    BigInt(422512);

    return 0;
}

void BigInt(unsigned int n) {
    unsigned int numOfDigits = getNumberOfDigits(n);
    int digits[numOfDigits];

//    int c = 0;
//    do
//    {
//        digits[c] = n % 10;
//        c++;
//    }
//    while ((n /= 10));


    // saving the digits to the array from right to left
    int c = numOfDigits;
    do
    {
        digits[c-1] = n % 10;
        c--;
    }
    while ((n /= 10));

    printIntArray(digits, sizeof(digits));

    for (int row = 0; row < NUMBER_OF_ROWS; row++)
    {
        for (int digit = numOfDigits; digit--;)
        {
            unsigned char bitPattern[sizeof(char)];
            for (char bit = 0; bit < sizeof(char); bit++)
                bitPattern[bit] = (digit >> bit) & 1;
            for (char bit = sizeof(char); bit--;)
                printf("%c", bitPattern[bit] == 1 ? '@' : ' ');

        }
        printf("\n");
    }

}

unsigned int getNumberOfDigits(unsigned int n)
{
    return log10(n) + 1;
}