#include <stdio.h>
#include <math.h>

void BigInt(unsigned int);

unsigned int getNumberOfDigits(unsigned int);

#define NUMBER_OF_ROWS 8
#define NUMBER_OF_BITS 8

/**
 * Digits are stored as bit patterns of 8-bit unsigned integer (char) numbers.
 *
 * Each digit requires just 8 bytes of storage - which is polynomially smaller
 * than the storage in brute-force approach where each digit is represented by
 * a 2D array of 8x8 characters, with 64 bytes of storage per digit.
 */
// const unsigned char BIG_DIGITS[NUMBER_OF_ROWS][10] = {
//        {       // row 0 of all 10 digits
//                0b00000000u, 0b00000000u, 0b00000000u, 0b00000000u, 0b00000000u,
//                0b00000000u, 0b00000000u, 0b00000000u, 0b00000000u, 0b00000000u
//        },
//
//        {       // row 1 of all 10 digits
//                0b00111110u, 0b00001100u, 0b00011110u, 0b00011110u, 0b00000110u,
//                0b00111111u, 0b00011110u, 0b01111111u, 0b00011110u, 0b00011110u
//        },
//
//        {       // row 2 of all 10 digits
//                0b01100011u, 0b00011100u, 0b00110011u, 0b00110011u, 0b00001110u,
//                0b00110000u, 0b00110011u, 0b00000011u, 0b00110011u, 0b00110011u
//        },
//
//        {       // row 3 of all 10 digits
//                0b01100011u, 0b00001100u, 0b00110011u, 0b00000011u, 0b00010110u,
//                0b00110000u, 0b00110000u, 0b00000110u, 0b00110011u, 0b00110011u
//        },
//
//        {       // row 4 of all 10 digits
//                0b01100011u, 0b00001100u, 0b00000110u, 0b00001100u, 0b00110110u,
//                0b00111110u, 0b00111110u, 0b00001100u, 0b00011110u, 0b00011111u
//        },
//
//        {       // row 5 of all 10 digits
//                0b01100011u, 0b00001100u, 0b00001100u, 0b00000011u, 0b01100110u,
//                0b00000011u, 0b00110011u, 0b00011000u, 0b00110011u, 0b00000011u
//        },
//
//        {       // row 6 of all 10 digits
//                0b01100011u, 0b00001100u, 0b00011000u, 0b00110011u, 0b01111111u,
//                0b00000011u, 0b00110011u, 0b00110000u, 0b00110011u, 0b00110011u
//        },
//
//        {       // row 7 of all 10 digits
//                0b00111110u, 0b00111111u, 0b00111111u, 0b00011110u, 0b00000110u,
//                0b00111110u, 0b00011110u, 0b01100000u, 0b00011110u, 0b00011110u
//        }
//};

// reverse digits:
const unsigned char BIG_DIGITS[8][10] = {

        {       // row0 of all 10 digits
                0b00000000u, 0b00000000u, 0b00000000u, 0b00000000u, 0b00000000u,
                0b00000000u, 0b00000000u, 0b00000000u, 0b00000000u, 0b00000000u
        },
        {       // row1 of all 10 digits
                0b01111100u, 0b00110000u, 0b01111000u, 0b01111000u, 0b01100000u,
                0b11111100u, 0b01111000u, 0b11111110u, 0b01111000u, 0b01111000u
        },
        {       // row2 of all 10 digits
                0b11000110u, 0b00111000u, 0b11001100u, 0b11001100u, 0b01110000u,
                0b00001100u, 0b11001100u, 0b11000000u, 0b11001100u, 0b11001100u
        },
        {       // row3 of all 10 digits
                0b11000110u, 0b00110000u, 0b11001100u, 0b11000000u, 0b01101000u,
                0b00001100u, 0b00001100u, 0b01100000u, 0b11001100u, 0b11001100u
        },
        {       // row4 of all 10 digits
                0b11000110u, 0b00110000u, 0b01100000u, 0b00110000u, 0b01101100u,
                0b01111100u, 0b01111100u, 0b00110000u, 0b01111000u, 0b11111000u
        },
        {       // row5 of all 10 digits
                0b11000110u, 0b00110000u, 0b00110000u, 0b11000000u, 0b01100110u,
                0b11000000u, 0b11001100u, 0b00011000u, 0b11001100u, 0b11000000u
        },
        {       // row6 of all 10 digits
                0b11000110u, 0b00110000u, 0b00011000u, 0b11001100u, 0b11111110u,
                0b11000000u, 0b11001100u, 0b00001100u, 0b11001100u, 0b11001100u
        },
        {       // row7 of all 10 digits
                0b01111100u, 0b11111100u, 0b11111100u, 0b01111000u, 0b01100000u,
                0b01111100u, 0b01111000u, 0b00000110u, 0b01111000u, 0b01111000u
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
//    int decimals[numOfDigits], bitPattern[NUMBER_OF_BITS];
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
            // solution for non-reversed digits:
//            // iteratively extracting each bit, starting from the least significant position
//            for (int bit = 0; bit < NUMBER_OF_BITS; bit++)
//                bitPattern[bit] = (BIG_DIGITS[row][decimals[digit]] >> bit) & 1;
//
//            // printing the most significant bits first
//            for (int bit = NUMBER_OF_BITS; bit >= 0; bit--)
//                printf("%c", bitPattern[bit] == 1 ? '@' : ' ');

            // iteratively extracting each bit from the bit pattern and printing it
            for (int bit = 0; bit < NUMBER_OF_BITS; bit++)
                printf("%c", ((BIG_DIGITS[row][decimals[digit]] >> bit) & 1) == 1 ? '@' : ' ');
        }
        puts("");
    }
}

unsigned int getNumberOfDigits(unsigned int n)
{
    return (unsigned int) log10(n) + 1;
}