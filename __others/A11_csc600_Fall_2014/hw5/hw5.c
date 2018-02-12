/**Write functions that perform the following
operations:
(a) Addition of polynomials
(b) Multiplication of polynomials
(c) Derivative(s) of polynomial
(d) Integral of polynomial
Write a main program that illustrates the work of your
functions. Use a procedural language of your choice.
**/

#include <stdio.h>
#include <stdlib.h> //memory allocation
#include <string.h>

int * addpoly(int * arr1, int * arr2, int terms);
int * mulpoly(int * arr1, int * arr2, int terms);
int * derivpoly(int * arr1, int terms);
double * integralpoly(int * arr1, int terms);
void printpoly(int * array, int terms);
void printpolyi(double * array, int terms);

int main()
{
	//make two polynomials as arrays
	int * poly1;
	int * poly2;
	int terms, i;

	terms = 3;
	poly1 = (int *)malloc(sizeof(int) * terms);
	poly2 = (int *)malloc(sizeof(int) * terms);
	for(i = 0; i< terms; i++){
		poly1[i] = i + 1;
		poly2[i] = i + 3;
	}
	printf("poly1:");
	printpoly(poly1,terms);
	printf("poly2:");
	printpoly(poly2,terms);

	//operate functions
	printf("poly1 + poly2:");
	printpoly(addpoly(poly1,poly2,terms),terms);
	printf("poly1 * poly2:");
	printpoly(mulpoly(poly1,poly2,terms),terms * terms);
	printf("derivative of poly1:");
	printpoly(derivpoly(poly1,terms),terms - 1);
	printf("integral of poly2:");
	printpolyi(integralpoly(poly2,terms),terms + 1);

	free(poly1);
	free(poly2);
	return 0;
}

/* function for (a) */	
int * addpoly(int * arr1, int * arr2, int terms){
	static int * answer;
	int i;
	answer = (int *)malloc(sizeof(int) * terms);
	for(i = 0; i < terms; i++){
		answer[i] = arr1[i] + arr2[i];
	}
	return answer;
}

/* function for (b) */	
int * mulpoly(int * arr1, int * arr2, int terms){
	static int * answer;
	int i, j, count = 0;
	answer = (int *)malloc(sizeof(int) * terms * terms);
	for(i = 0; i < terms; i++){
		for(j = 0; j < terms; j++)
		{
			answer[count++] = arr1[i] * arr2[j];
		}
	}
	return answer;
}

/* function for (c) */	
int * derivpoly(int * arr1, int terms){
	static int * answer;
	int i;
	answer = (int *)malloc(sizeof(int) * terms - 1);
	for(i = 1; i < terms; i++){
		answer[i - 1] = arr1[i] * i;
	}
	return answer;
}

/* function for (d) */	
double * integralpoly(int * arr1, int terms){
	static double * answer;
	int i;
	answer = (double *)malloc(sizeof(double) * terms + 1);
	for(i = 0; i < terms; i++){
		answer[i + 1] = (double)arr1[i] / (i + 1);
	}
	return answer;
}

void printpoly(int * array, int terms){
	int i;
	printf("f(x)= %d", *array);
	for(i = 1; i < terms; i++){
		printf(" + %dx^%d", *(array + i), i);
	}
	printf("\n");
	return;
}

void printpolyi(double * array, int terms){
	int i;
	printf("f(x)= C");
	for(i = 1; i < terms; i++){
		printf(" + %fx^%d", *(array + i), i);
	}
	printf("\n");
	return;
}
