#include <iostream>
#include <math.h>
#include <iomanip>
#include <stdio.h>
using namespace std;

int main(void)
{	
	//1. Show that for unsigned int a,b and a>0, b>0, we can get a+b < a
	{
	unsigned char a = 255;
	unsigned char b = 1;
	unsigned char c = a+b;
	int d = c;
	cout << "\nSegment 1:\n" << d << endl;
	}

	//2. Show that for int a,b and a>0, b>0, we can get a+b < 0
	{
	char a = 128;
	char b = 1;
	int c = a+b;
	cout << "\nSegment 2:\n" << c << endl;
	}

	//3. Show that for int a,b and a<0, b<0, we can get a+b > 0
	{
	char a = -128;
	char b = -1;
	char c = a+b;
	int d = c;
	cout << "\nSegment 3:\n" << d << endl;
	}

	//4. Show that for double x and x>0 we can get 1. + x = = 1.
	{
	double x = .000003;
	double c = 1. + x;
	cout << "\nSegment 4:\n" << c << endl;
	}

	//5. Show that for double a,b,c in some cases (a+b)+c != (c+b)+a
	{
	double a = 12.34;
    double b = 0.0000000000005;
    double c = 0.0000000000005;
    double abSum = a+b;
    double firstResult = abSum + c;
    cout << "\nSegment 5:\n" << setprecision(20) << firstResult << endl;
    double cbSum = c+b;
    double secondResult = cbSum + a;
    cout << setprecision(20) << secondResult << endl;
        if(firstResult != secondResult)
        	cout <<"They're not equal" << endl;
        else{
        	cout << "They're equal" << endl;
        }
	}

	/*6. Show the results of the following power function:
	pow(-2., 3), pow(-2., 3.0) , pow(-2., 3.00000000001)*/
	{
	cout << "\nSegment 6:\n" <<pow(-2.,3) << endl;
	cout << pow(-2.,3.0) << endl;
	cout << pow(-2,3.00000000001) << endl;
	}

	//7. Show the memory size of the following constants 1. , 1.F, 1 , '1' , and "1"
	{
	cout << "\nSegment 7:\nsize of 1. is " << sizeof(1.) << endl;
	cout << "size of 1.F is " << sizeof(1.F)<< endl;
	cout << "size of 1 is " << sizeof(1) << endl;
	cout << "size of '1' is " << sizeof('1') << endl;
	cout << "size of \"1\" is " << sizeof("1") << endl;
	}

	//8. Display 1./3. using 20 digits and show the correct and incorrect digits
	{
	double b = 1./3.;
	cout << "\nSegment 8:\nwith only 5 digits: " << setprecision(5) << b << endl;
	cout << "With 20 digits:  " << setprecision(20) << b << endl;
	}

	/*9. Display all printable characters of the ASCII table in 3 columns:
	first column: 32-63, second column: 64-95, third column: 96-127. Each column
	must include the numeric value and the corresponding character. Following is
	an example of one of 32 rows in the ASCII table:
					33 ! 65 A 97 a*/
	{
	char a;
	char b;
	char c;
	cout <<"\nSegment 9:\n";
	for(int i = 0; i<32; i++)
		{
		a = (char) i+32;
		b = (char) i+64;
		c = (char) i+96;
		cout << i+32 << ". " << a << "   " << i+64 
		<< ". " << b << "   " << i+96 << ". "<< c << endl;
		}
	}

	//10. Compute sqrt(2.) using your own program for square root function.
	{
	double m = 2.;
	double n = m /2.0;
	double z = 0.0;
	while(n != z)
	{
		z = n;
		n = (n + m/n) /2.0;
	}
	cout << "\nSegment 10:\n" <<setprecision(7) << n << endl;
	}
}


