// Nehemya McCarter-Ribakoff
// Dujmovic
// HW2
// 29 September 2017

#include <iostream>

/* array for printing digits. The column index *
 * corresponds to the digit to print            */                          

void bigInt(int);

int main() {

    int inputNumber;

    std::cout << "Enter a digit: ";
    std::cin >> inputNumber;
    bigInt(inputNumber);

    return 0;
}

void bigInt(int n) {
    std::string digits[7][10] = {
    {" @@@@@ ", "   @@  ", "@@@@@@@", "@@@@@@@", "@@   @@", "@@@@@@@", 
     "     @@", "@@@@@@@", " @@@@@ ", " @@@@@ "},

    {"@@   @@", "  @@@  ", "     @@", "     @@", "@@   @@", "@@    ", 
     "   @@  ", "     @@", "@@   @@", "@@   @@"},

    {"@@   @@", "   @@  ", "    @@ ", "     @@", "@@   @@", "  @@   ", 
     " @@    ", "    @@ ", "@@   @@", "@@   @@"},

    {"@@   @@", "   @@  ", " @@    ", "  @@@@@", "@@@@@@@", "    @@ ", 
     "@@@@@@@", "   @@  ", "@@@@@@@", "@@@@@@@"},

    {"@@   @@", "   @@  ", "@@     ", "     @@", "     @@", "     @@", 
     "@     @", "  @@   ","@@   @@", "    @@ "},

    {"@@   @@", "   @@  ", "@@     ", "     @@", "     @@", "     @@", 
     "@     @", " @@    ", "@@   @@", "    @@ "},

    {" @@@@@ ", "@@@@@@@", "@@@@@@@", "@@@@@@@", "     @@", "@@@@@@ ", 
     "@@@@@@@" , "@@     ", " @@@@@ ", " @@@   "}

    };

    int numberArray[256]; // to store individual digits of input value
    int numberOfDigits = 0;
    std::string printString = "";

    while (n) {
        numberArray[numberOfDigits++] = n % 10; // assigns leftmost digit
        n /= 10; // remove leftmost digit
    }


    for (int index = 0; index < 7; index++) {
        for (int digit = numberOfDigits - 1; digit >= 0 ; digit--) {
            printString += digits[index][numberArray[digit]];
            printString += "   ";
        }
        std::cout << printString << "\n";
        printString = "\0";
    }
}

