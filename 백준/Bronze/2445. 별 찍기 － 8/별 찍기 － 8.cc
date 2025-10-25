#include <iostream>
#include <iomanip>
#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int N;
	std::cin >> N;

	for (int i = 1; i < N; ++i)
	{
		for (int j = 0; j < i; ++j)
			std::cout << '*';

		for (int j = 1; j <= 2 * N - (2 * i); ++j)
			std::cout << ' ';

		for (int j = 0; j < i; ++j)
			std::cout << '*';

		std::cout << '\n';
	}

	for (int i = 0; i < N * 2; ++i)
		std::cout << '*';
	std::cout << '\n';

	for (int i = N - 1; i >= 1; --i)
	{
		for (int j = 0; j < i; ++j)
			std::cout << '*';

		for (int j = i; j < 2 * N - i; ++j)
			std::cout << ' ';

		for (int j = 0; j < i; ++j)
			std::cout << '*';

		std::cout << '\n';
	}

	return 0;
}