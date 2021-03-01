#include <iostream>
#include "matrix.h"

int main()
{
	// constructor 
	Matrix<int> a(2,2,1);
	Matrix<int> b(2,2,2);

	// get number of rows and columns
	std::cout << a.get_ncol() << std::endl;
	std::cout << a.get_nrow() << std::endl;

	// matrix multipication
	Matrix<int> c = a * b;

	// scalar multiplication and addition
	int d = 10;
	Matrix<int> e = c * d;
	e += d;
	c = e + d;


	std::cout << c(0,0) << ", " << c(0,1) << std::endl
			<< c(1,0) << ", " << c(1,1) << std::endl;

}