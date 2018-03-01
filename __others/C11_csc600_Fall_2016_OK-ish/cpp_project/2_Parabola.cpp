#include <iostream>
#include <iomanip>
using namespace std;


double insert(double x1, double y1, double x2, double y2, double x3, double y3, double x)
{
	double a,b,c;
	int i;
	//Instantiate matrix for Gaussian elimination
	double matrix[][4]={{(x1*x1),x1,1,y1},{(x2*x2),x2,1,y2},{(x3*x3),x3,1,y3}};
	for(i=0;i<4;i++)
	{ //Eliminate c from the 2nd and 3rd row because they are always 1
		matrix[1][i]-=matrix[0][i];
		matrix[2][i]-=matrix[0][i];
	}
	double temp=(matrix[2][0]/matrix[1][0]);
	for(i=0;i<4;i++) //Eliminate a from the third row, to solve for b
		matrix[2][i]-=(double)matrix[1][i]*temp;
	
	b=matrix[2][3]/matrix[2][1];//solve for b
	a=(matrix[1][3]-(b*matrix[1][1]))/matrix[1][0];//plug in b to solve a
	//plug in a and b to solve for c
	c=(matrix[0][3]-(b*matrix[0][1])-(a*matrix[0][0]))/matrix[0][2];
	//return the value at x with found a, b, and c
	return (a*x*x)+(b*x)+c;
	
}

double lagrange(double x1, double y1, double x2, double y2, double x3, double y3, double x)
{
	//lagrange equation
	return y1*(((x-x2)*(x-x3))/((x1-x2)*(x1-x3))) +
		   y2*(((x-x1)*(x-x3))/((x2-x1)*(x2-x3))) +
		   y3*(((x-x1)*(x-x2))/((x3-x1)*(x3-x2)));
}

int main (){
	double x1,x2,x3,y1,y2,y3;
	int i; //get input
	cout << "Interpolating 40 Parabola points based on your input" << endl;
	cout << "Input x1, y1, x2, y2, x3, y3 of your parabola" <<endl;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	double neX;
	cout<<"    x | insert |lagrange\n"; //formatting for table
	for(i=0;i<41;i++)
	{ //loop through, getting 0, max and 40 inbetween values
		neX=(double)(x1+((x3-x1)/40)*i);
		cout<< setw(5)<<neX<<" |";
		//Get the insert val then the lagrange val, printing to the table
		cout<< setw(8)<<insert(x1, y1, x2, y2, x3, y3,neX)<<"|";
		cout<< setw(8)<<lagrange(x1, y1, x2, y2, x3, y3,neX)<<endl;
		//For the insert method I thought it would be easier to only 
		//calculate a, b, and c once then get all the values,
		//but the assignment said to do it like this so i did.
	}
}
