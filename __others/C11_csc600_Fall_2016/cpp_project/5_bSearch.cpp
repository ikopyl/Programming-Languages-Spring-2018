#include <iostream>
#include <time.h>
using namespace std;

int bsI(int* a, int n, int x){
	int min=0,max=n,mid;
	do
	{
		if(min>max) return -1;
		mid= (min+max)/2;
		if(a[mid]>a[x])
			max=mid;
		if(a[mid]<a[x])
			min=mid;	
	}while(a[mid]!=a[x]);
	return mid;
}
int bsR(int* a, int min, int max, int x){
	int mid= (min+max)/2;
	if(min>max) return -1;
	if (a[mid]==a[x]){
		return mid;
	}
	if(a[mid]>a[x])
		return bsR(a,min,mid,x);
	if(a[mid]<a[x])
		return bsR(a,mid,max,x);
	return -1;
}

int main (){
	int n=1000000; //1 mill was the most i could get without exeption
	int a[n];
	int i,j,t1,t2;
	for(i=0; i<n;i++)
		a[i]=i; //instantiate array
	t1=clock();//start clock for iterative
	for(j=0; j<25;j++)
		for(i=0;i<n;i++) if (bsI(a,n,i)!=i) cout<<"ERROR"<<endl;
		//search on every array slot, 25 times
	t2=clock();//end clock for iterative
	cout<<"ITERATIVE SEC: "<<(double)(t2-t1)/CLOCKS_PER_SEC<<endl;//print clock
	
	t1=clock();//start clock for recursive
	for(j=0; j<25;j++)
		for(i=0;i<n;i++) if (bsR(a,0,n,i)!=i) cout<<"ERROR"<<endl;
		//search on every array slot, 25 times
	t2=clock();//end clock on recursive
	cout<<"RECURSIVE SEC: "<<(double)(t2-t1)/CLOCKS_PER_SEC<<endl;//print clock
	
}
