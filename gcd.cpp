//gcd.cpp :: Pritesh verma
//Descriptiom:: Following program computes greatest common divisor of two numbers

#include <iostream>

using namespace std;

//function returns gcd of two numbers
int gcd(int m, int n){
	//Everything divides zero
	if(m == 0)
		return n;
	if(n == 0)
		return m;
	//base case
	if(m == n)
		return n;

	if (m > n)
		return gcd(m-n,n);

	return gcd(m, n-m);

}

int main(){

//input
	int m,n;
	cout<<"Enter two numbers\n";
	cout<<"Enter first number\n";
	cin>>m;
	cout<<"Enter second number\n";
	cin>>n;
//Result
	cout<<"Greatest common divisor of "<<m<<" and "<<n<< " is: "<<gcd(m,n);
	cout<<endl;

	return 0;
}