#include <iostream>
using namespace std;

void add(int a[],int na, int b[],int nb){// ADDITION
	int maxlen=nb;
	if(na>nb) maxlen=na;// find bigger array size
	int c[maxlen]; //result in c

	int i;
	for(i=0;i<maxlen;i++)
		c[i]=0; //init all c to 0
	for(i=0;i<na;i++)
		c[i] += a[i]; //add a to c
	for(i=0;i<nb;i++)
		c[i] += b[i]; //add b to c
	
	for(i=0;i<maxlen;i++){ //print all of c
		cout<<c[i]<<"X^"<<i;
		if(i+1<maxlen) cout<< " + ";
	}
	cout<<endl;
} 
void mult(int a[], int na, int b[],int nb){// MULTIPLY
	int maxlen = na+nb-1;
	int c[maxlen];
	int i,j; 
	for(i=0;i<maxlen;i++)
		c[i]=0; //init all c to 0

	for(i=0;i<na;i++)
		for(j=0;j<nb;j++)
			c[i+j] += a[i]*b[j];
			
	for(i=0;i<maxlen;i++){ //print all of c
		cout<<c[i]<<"X^"<<i;
		if(i+1<maxlen) cout<< " + ";
	}
	cout<<endl;		
}

void der(int a[],int na){// 	DERIVATIVE
	int maxlen = na-1;
	int c[maxlen];
	int i; 
	for(i=1;i<na;i++)
		c[i-1] = a[i]*i;
					
	for(i=0;i<maxlen;i++){ //print all of c
		cout<<c[i]<<"X^"<<i;
		if(i+1<maxlen) cout<< " + ";
	}
	cout<<endl;	
}
void integ(int a[],int na){//	INTEGRAL
	int maxlen = na+1;
	double c[maxlen];
	int i;
	for(i=0; i<na;i++)
		c[i+1] = (double)a[i]/(double)(i+1);
	
	cout<<"C + ";
	for(i=1;i<maxlen;i++){ //print all of c
		cout<<c[i]<<"X^"<<i;
		if(i+1<maxlen) cout<< " + ";
	}
	cout<<endl;	
}

int main (){
	int i;
	int poly1[3]={6,3,2};
	int poly2[4]={2,1,1,3};
	char str1[] = "6X^0 + 3X^1 + 2X^2";
	char str2[] = "2X^0 + 1X^1 + 1X^2 + 3X^3";
	
	cout<<"\t\tADDITION\n"<< str1<< " + \n"<<str2<< " = \n";
	add(poly1,3,poly2,4);
	cout<<"\t\tMULTIPLICATION\n"<< str1<< " * \n"<<str2<< " = \n";
	mult(poly1,3,poly2,4);
	cout<<"\t\tDERIVATIVE\nd/dx "<<str2<<"\nis:  ";
	der(poly2,4);
	cout<<"\t\tINTEGRAL\nintegral of "<<str2<<"\nis: ";
	integ(poly2,4);
}
