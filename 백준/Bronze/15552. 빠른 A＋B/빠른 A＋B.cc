#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int Number;
	std::cin >> Number;

	int A, B;
	for (int i = 0; i < Number; ++i)
	{
		std::cin >> A >> B;
		std::cout << A + B << "\n";
	}

	return 0;
}