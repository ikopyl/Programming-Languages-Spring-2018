#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Calculates the y value
double y(double x1, double y1, double x2, double y2, double x3, double y3, double x) {
    //get pow to be used in Cramers Rule
    double x1pow = pow(x1, 2);
    double x2pow = pow(x2, 2);
    double x3pow = pow(x3, 2);
    
    //Cramers Rule
    double det = (x1pow*(x2 - x3)) - (x1*(x2pow - x3pow)) + (x2pow*x3 - x3pow*x2);
    double a = ((y1*(x2 - x3)) - (x1*(y2-y3)) + (y2*x3 - y3*x2))/det;
    double b = ((x1pow*(y2 - y3)) - (y1*(x2pow - x3pow)) + (x2pow*y3 - x3pow*y2))/det;
    double c = ((x1pow*(x2*y3 - x3*y2)) - (x1*(x2pow*y3 - x3pow*y2)) + (y1*(x2pow*x3 - x3pow*x2)))/det;
    
    int y = ((a*(x*x)) + (b*x) + c);;
    return y;
}

int main(void) {
    //The user will choose these values
    double x1, x2, x3, y1, y2, y3;
    double x;
    //used in for loop to obtain 40 points
    int n = 40;
    
    //get the numbers from the user
    cout << "Choose values in order: x1 y1 x2 y2 x3 y3" << endl;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    cout << "x column \t \t y column" << endl;
    for (int i = 0; i < n; i++) 
    {
        //Calculates X
        x = x1 + i*((x3 - x1)/n);
        //prints X and Y up to three decimal points.
        cout << fixed << setprecision(3) << x << "\t\t\t" <<  y(x1, y1, x2, y2, x3, y3, x) << endl;
    }
    
    return 0;
}
