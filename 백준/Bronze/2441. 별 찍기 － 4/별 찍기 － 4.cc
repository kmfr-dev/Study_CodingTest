#include <iostream>
#include <iomanip>
#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int Number;
	std::cin >> Number;

	for (int i = 0; i < Number; ++i)
	{
		std::string Stars(Number - i, '*');
		std::cout << std::setw(Number) << std::right << Stars << "\n";
	}

	return 0;
}