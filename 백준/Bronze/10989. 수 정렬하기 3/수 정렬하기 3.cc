#include <iostream>
#include <vector>

const int MaxNumber = 10000;

int main()
{
	// 입력 받을 케이스를 선언한다.
	int Case = { 0 };
	// 입력을 받는다.
	std::cin >> Case;
	
	int Arr[MaxNumber] = { 0 };
	
	for (int i = 0; i < Case; ++i)
	{
		int Number = { 0 };
		std::cin >> Number;
		Arr[Number - 1] += 1;
	};

	for (int i = 0; i < MaxNumber; ++i)
	{
		for (int j = 0; j < Arr[i]; ++j)
			std::cout << i + 1 << '\n';
	}
	
}