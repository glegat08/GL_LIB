#include "Files.h"
using namespace Glib;

int main()
{
	//Matrix mat1 = 
	//{
	//	{1, 2},
	//	{3, 4}
	//};

	//Matrix mat2 =
	//{
	//	{5},
	//	{7}
	//};

	//mat1.Print();
	//std::cout << std::endl;
	//mat2.Print();

	//std::cout << "\nAfter Matrix Multiplication with mat2:\n";
	//mat1.MultiplyMatrix(mat2);
	//mat1.Print();

	//std::cout << "\nIdentity of mat1:\n";
	//mat1.Idenity();
	//mat1.Print();

	//std::cout << "\nCoefficient at (1,1) in mat1: ";
	//int value;
	//mat1.Coefficient(1, 1, value);
	//std::cout << value << std::endl;

	//std::cout << "\nDimensions of mat1: " << mat1.GetRow() << "x" << mat1.GetCol() << std::endl;

	//std::cout << "\nAfter Addition:\n";
	//mat1.MatrixAddition(mat2);
	//mat1.Print();

	//std::cout << "\nAfter Scalar Multiplication by 2:\n";
	//mat1.ScalarMultiply(2);
	//mat1.Print();

	//std::ifstream f("C:\\Users\\guill\\Desktop\\test.txt");
	//FileReader reader;
	//reader.readFile(f);

	Random rand;

	int i = rand.get(1,10);
	float f = rand.get(1.5f, 9.5f);
	std::cout << i << std::endl;
	std::cout << f << std::endl;

	std::cout << std::endl;

	Matrix mat3(3, 3);
	mat3.RandomMatrix(rand, 0, 9);

	mat3.Print();

	return 0;
}