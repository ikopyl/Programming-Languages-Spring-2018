// Nehemya McCarter-Ribakoff
// Dujmovic
// HW2
// 29 September 2017

#include <iostream>
// y = ax^2 + bx + c

typedef struct {
    double** data;
    int rows;
    int columns;
} matrix;

void approximateCurve(int x1, int y1, int x2, int y2, 
                      int x3, int y3, int x);
int main() {


return 0;
}

void approximateCurve(int x1, int y1, int x2, int y2, 
                      int x3, int y3, int x) {

    matrix system;
    int a, b, c;

    system.rows = 3;
    system.columns = 4;
    system.data = {[a, pow(x1, 2), b * x1];
    
    int row = 0, column = 0;
    for (row = 0; row < self.rows; row++) { 
        system.data[row] = malloc(self.rows * sizeof(int));
    }   
    for (row = 0; row < system.rows; row++) {
        for (column = 0; column < system.columns; column++) {
            system.data[row][column] = matrix[row][column];
            printf("%f, ", self.data[row][column]);
        }
    }   

    /*
    y1 = ax1^2 + bx1 + c
    y2 = ax2^2 + bx2 + c
    y3 = ax3^2 + bx3 + c
    

    ax1^2 = y1 - bx1 + c
    a = (y1 - bx1 + c) / x1^2
    b = (y1 - ax1^2 - c) / x1
    c = y1 - ax1^2 - bx1
    */

}
