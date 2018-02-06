/**We know three points on a curve: (x1, y1), (x2, y2), (x3, y3) . You have to create a
program that for any value x1 ≤ x ≤ x3 computes the corresponding value y assuming that
the segment of curve can be approximated with the parabola y = ax2 + bx + c . Write a
function that can be called as y(x1,y1,x2,y2,x3,y3,x) and a main program that
reads x1,y1,x2,y2,x3,y3 and then displays y(x1,y1,x2,y2,x3,y3,x) in n=40
points between x1 and x3.
**/

#include <stdio.h>
#include <string.h>

void y(int x1, int y1, int x2, int y2, int x3, int y3, float x);

int main()
{
	int x1, y1, x2, y2, x3, y3;
	float x;
	//get input for x1, y1, x2, y2, x3, y3
	printf("Enter x1, y1, x2, y2, x3, y3: ");
	if(scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3) == 6)
	{
		//display the given input
		printf("(x1, y1) = (%d, %d), (x2, y2) = (%d, %d), (x3, y3) = (%d, %d)\n",
			 x1, y1, x2, y2, x3, y3);
		y(x1, y1, x2, y2, x3, y3, x);
	}
	else
	{
		printf("Error: Did not recive 6 numbers\n");
	}
	return 0;
}

//solve the parabola and display 40 points in between
void y(int x1, int y1, int x2, int y2, int x3, int y3, float x)
{
	int a, b, c, count;
	//algebraic computation for solving a parabola
	a = (((y1-y2)*(x1-x3)) - ((x1-x2)*(y1-y3)))
		/(((x1*x1 - x2*x2)*(x1-x3)) - ((x1-x2)*(x1*x1 - x3*x3)));
	b = ((y1-y2)-(((x1*x1) - (x2*x2))*a))/(x1-x2);
	c = y1 - ((x1*x1)*a) - (x1*b);

	printf("The parabola is y = %dx^2 + %dx + %d \n", a, b, c);

	//get 40 points and display on console
	for(count = 1; count <= 40; count++)
	{
		float countf = (float)count;
		x = ((x3 - x1)/40.0)*countf;
		printf("(%.2f, %.2f) ", x, (a*x*x + b*x + c));
	}
	printf("\n");
	return;
}
