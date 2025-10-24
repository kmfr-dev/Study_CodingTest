#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int Number;
	std::cin >> Number;

	for (int i = 0; i < Number; ++i)
	{
		for (int j = Number - i; j >= 1; --j)
			std::cout << "*";
		std::cout << "\n";
	}

	return 0;
}