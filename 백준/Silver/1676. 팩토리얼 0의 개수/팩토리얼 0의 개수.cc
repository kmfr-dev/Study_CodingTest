#include <iostream>
#include <cmath>

int Factorial(int Number)
{
	int Result{ 0 };

	for (int i = 5; i <= Number; i*= 5)
		Result += Number / i;

	return Result;
};

int main()
{
	int Number = { 0 };
	std::cin >> Number;

	int Result = Factorial(Number);
	std::cout << Result << std::endl;

	return 0;
}