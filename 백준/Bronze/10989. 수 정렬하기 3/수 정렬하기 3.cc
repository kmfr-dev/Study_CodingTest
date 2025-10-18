#include <iostream>

// 입력 가능한 최대 수
const int MaxNumber = 10000;

int main()
{
	// 입력 개수
	int Case = { 0 };
	std::cin >> Case;
	
	// 각 숫자의 등장 횟수를 저장할 배열
	int Arr[MaxNumber] = { 0 };
	
	// 입력된 숫자들의 개수를 센다
	for (int i = 0; i < Case; ++i)
	{
		int Number = { 0 };
		std::cin >> Number;
		Arr[Number - 1] += 1;
	};

	// 등장 횟수만큼 숫자를 오름차순으로 출력
	 // std::endl 대신 개행으로 출력 속도 최적화
	for (int i = 0; i < MaxNumber; ++i)
	{
		for (int j = 0; j < Arr[i]; ++j)
			std::cout << i + 1 << '\n';
	}
}