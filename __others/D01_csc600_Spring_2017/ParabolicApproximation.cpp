/********************************
 * Hasan Niftiyev
 * CSC 600 - Homework 2
 * Problem 2: Array Processing
We know three points on a curve: (x1, y1), (x2, y2), (x3, y3) . You have to create a 
program that for any value x1 <= x <= x3 computes the corresponding value y assuming 
that the segment of curve can be approximated with the parabola y = ax + bx + c 2. 
Write a function that can be called as y(x1,y1,x2,y2,x3,y3,x) and a main program that
 reads x1,y1,x2,y2,x3,y3 and then displays y(x1,y1,x2,y2,x3,y3,x) in n=40 equidistant 
 x points between x1 and x3.

Resources:
http://www.purplemath.com/modules/cramers.htm
http://mathonline.wikidot.com/quadratic-lagrange-interpolating-polynomials
 * ******************************/


#include <iostream>
#include <iomanip> 
#define subsection 40;

using namespace std;

void y(double,double,double,double,double,double);
void yCramers(double,double,double,double,double,double);
void yLagrange(double,double,double,double,double,double);
double L(double,double,double);

int main(){

	// Initialized three points coordinates.
	double x1,y1,x2,y2,x3,y3;

	// User input
	cout << "Enter three coordinates as x1,y1,x2,y2,x3,y3: " ;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	y(x1,y1,x2,y2,x3,y3);


	return 0;
}

//General function for coefficients on three points parabolic approximation.
void y(double x1, double y1 , double x2 , double y2 , double x3 , double y3){

	if ( (x1 == x2) || (x2 == x3) || (x3 == x1))

		cout << "Invalid Input! Submit unique values" << endl;

	else{

		cout << " ======= Cramer's Coefficients  ======= " <<endl;
		yCramers(x1,y1,x2,y2,x3,y3);	
	}

}

//Quadratic Lagrange Interpolating Polynomial - L function see Resources.
double L(double a , double b , double c ){

	return ((a - b) * (a - c));

}

// Function that finds coefficients and prints it first by Cramers rule followed by Lagrange.
void yCramers(double x1 , double y1 , double x2 , double y2 , double x3 , double y3){

	double a1 = x1 * x1, b1 = x1, c1 = 1, d1 = -y1,
    a2 = x2 * x2, b2 = x2, c2 = 1, d2 = -y2,
    a3 = x3 * x3, b3 = x3, c3 = 1, d3 = -y3;
    
    
    // D, Dx/D , Dy/D , Dz/D - Cramers rule - See Resource - 
    double D = (a1 * b2 * c3 + b1 * a3 * c2 + c1 * a2 * b3) - (a1 * c2 * b3 + b1 * a2 * c3 + c1 * b2 * a3);
    double x = ((b1 * c3 * d2 + c1 * b2 * d3 + d1 * c2 * b3) - (b1 * c2 * d3 + c1 * b3 * d2 + d1 * b2 * c3)) / D;
    double y = ((a1 * c2 * d3 + c1 * a3 * d2 + d1 * a2 * c3) - (a1 * c3 * d2 + c1 * a2 * d3 + d1 * c2 * a3)) / D;
    double z = ((a1 * b3 * d2 + b1 * a2 * d3 + d1 * b2 * a3) - (a1 * b2 * d3 + b1 * a3 * d2 + d1 * a2 * b3)) / D;
    
    // Prints coefficients according to Cramers
    cout << "\ta\tb\tc\n";
    cout << "\t" << setprecision(2) << x << "\t" << setprecision(2) << y << 
    			"\t" << setprecision(2) << z << fixed << "\n"<< endl;
 
    cout << " ======= Lagrange's Coefficients =======" <<endl;
		yLagrange(x1,y1,x2,y2,x3,y3);

	// As a requirement, orinting 40 equidistant x and relative y.
 	double segment = (x3 - x1) / 39 ; //subsection;
 	int counter = 1;
		cout << "======= 40 equidistant points between x1 and x3 =======\n";
	 for(double instance = x1; instance < x3; instance += segment, counter++){
        double Y = x * (instance * instance) + y * (instance) + z;
        cout << counter << ":\t(" << setprecision(2) << instance << " , " << setprecision(2) << fixed << Y << ")" << endl;
   
	}
}

void yLagrange(double x1 , double y1 , double x2 , double y2 , double x3 , double y3) {
	double x,y,z;

	// Lagrange rule -  See Resource
	x = (y1/L(x1,x2,x3)) + (y2/L(x2,x1,x3)) + (y3/L(x3,x1,x2));
	y = -(((y1 * (x2 + x3))/L(x1,x2,x3)) + ((y2 * (x1 + x3)) / L(x2,x1,x3)) + ((y3 * (x1 + x2)) / L(x3,x1,x2)));
   	z = (((y1 * x2 * x3) /  L(x1,x2,x3)) + ((y2 * x1 * x3) /  L(x2,x1,x3)) + ((y3 * x1 *x2) / L(x3,x1,x2)));

   	// Prints coefficients according to Cramers
   	cout << "\ta\tb\tc\n";
    cout << "\t" << setprecision(2) << x << "\t" << setprecision(2) << y <<
    			 "\t" << setprecision(2) << z << fixed << "\n" << endl;

    }




