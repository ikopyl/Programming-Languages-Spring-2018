#include <iostream>
#include <stdlib.h>

using namespace std;

// write a function sum(n) that returns the sum of bits in the binary representation of n
// for example, sum(6) returns 1+1+0 = 2
// write both iterative and recursive solutions

// toBinary
// accepts an integer
// returns the binary form
int toBinaryIterative(int integer) {

	return 0;
}

int toBinaryRecursive(int n) {
	int binary;

	while(n !=0){
		binary = (n%2 == 0 ? 0 : 1) + binary;
		n /= 2;
	}

	return binary;
}


int main() {
	int input;
	cin >> input;

	cout << toBinaryRecursive(input) << endl;

	return 0;
}