#include "Files.h"
using namespace Glib;

int main()
{
	Matrix mat1 = 
	{
		1, 2,
		3, 4
	};

	Matrix mat2 =
	{
		5, 6,
		7, 8
	};

	mat1.Print();
	std::cout << std::endl;
	mat2.Print();

	std::cout << "\nAfter Identity on mat1:\n";
	mat1.Idenity();
	mat1.Print();

	std::cout << "\nAfter Matrix Multiplication with mat2:\n";
	mat1.MultiplyMatrix(mat2);
	mat1.Print();

	std::cout << "\nCoefficient at (1,1) in mat1: ";
	int value;
	mat1.Coefficient(1, 1, value);
	std::cout << value << std::endl;

	std::cout << "\nDimensions of mat1: " << mat1.GetRow(mat1) << "x" << mat1.GetCol(mat1) << std::endl;

	std::cout << "\nAfter Addition:\n";
	mat1.MatrixAddition(mat2);
	mat1.Print();

	std::cout << "\nAfter Scalar Multiplication by 2:\n";
	mat1.ScalarMultiply(2);
	mat1.Print();

	return 0;
}