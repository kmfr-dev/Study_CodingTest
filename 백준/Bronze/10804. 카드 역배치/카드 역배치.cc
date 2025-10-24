#include <iostream>
#include <algorithm>

int Cards[20], A, B;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	// 배열을 채워준다.
	for (int i = 0; i < 20; ++i)
		Cards[i] = i + 1;
		
	// 구간을 입력받고 해당 구간을 뒤집어준다
	for (int i = 0; i < 10; ++i)
	{
		std::cin >> A >> B;
		std::reverse(Cards + (A - 1), Cards + B);
	}

	// 출력
	for (int i = 0; i < 20; ++i)
		std::cout << Cards[i] << " ";

	return 0;
}