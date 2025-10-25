#include <iostream>
#include <iomanip>
#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int N;
	std::cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 0; j < N - i; ++j)
			std::cout << ' ';

		for (int k = 1; k <= 2 * i - 1; ++k)
			std::cout << '*';

		std::cout << '\n';
	}

	for (int i = N - 1; i >= 1; --i)
	{
		for (int j = 0; j < N - i; ++j)
			std::cout << ' ';

		for (int k = 1; k <= 2 * i - 1; ++k)
			std::cout << '*';

		std::cout << '\n';
	}

	return 0;
}