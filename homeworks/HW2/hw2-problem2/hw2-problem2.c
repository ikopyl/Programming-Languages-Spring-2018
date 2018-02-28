#include <stdio.h>
#include <math.h>

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
#define NUMBER_OF_BITS 8

const unsigned char BIG_DIGITS[NUMBER_OF_ROWS][10] = {

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
    BigInt(1);
    BigInt(12);
    BigInt(123);
    BigInt(1234);
    BigInt(1234567890);

    return 0;
}

void BigInt(unsigned int n)
{
    unsigned int numOfDigits, c;
    c = numOfDigits = getNumberOfDigits(n);
    int decimals[numOfDigits];

    // decomposing the number into an array of decimal digits
    do {
        decimals[c-1] = n % 10;
        c--;
    } while ((n /= 10));

    // printing all digits at once, row by row
    for (int row = 0; row < NUMBER_OF_ROWS; row++)
    {
        for (int digit = 0; digit < numOfDigits; digit++)
        {
            int bitPattern[NUMBER_OF_BITS];

            // iteratively extracting each bit, starting from the least significant position
            for (int bit = 0; bit < NUMBER_OF_BITS; bit++)
                bitPattern[bit] = (BIG_DIGITS[row][decimals[digit]] >> bit) & 1;

            // printing the most significant bits first
            for (int bit = NUMBER_OF_BITS; bit >= 0; bit--)
                printf("%c", bitPattern[bit] == 1 ? '@' : ' ');
        }
        puts("");
    }

}

unsigned int getNumberOfDigits(unsigned int n)
{
    return (unsigned int) log10(n) + 1;
}