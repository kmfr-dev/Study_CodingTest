#include <iostream>
#include <string>

int main()
{
	std::string ISBN = { "" };
	std::cin >> ISBN;

	// 자릿수의 합을 저장할 변수와
	// 훼손될 자리의 가중치를 구할 변수
	int Sum = { 0 };
	int MissingWeight = { 0 };

	for (int i = 0; i < ISBN.length(); ++i)
	{
		// i번째 요소가 *일 때
		if (ISBN[i] == '*')
		{
			// 현재 자리의 가중치를 구하고 건너뛴다.
			MissingWeight = (i + 1) % 2 == 0 ? 3 : 1;
			continue;
		}

		// 현재 자릿수의 가중치를 구해서
		// i번째 숫자와 가중치를 곱한 다음 더한다.
		int Weight = (i + 1) % 2 == 0 ? 3 : 1;	
		Sum += (ISBN[i] - '0') * Weight;
	}
	
	// 0부터 9까지 반복
	for (int i = 0; i <= 9; ++i)
	{
		// 합과 i번째 요소를 더하고 훼손된 숫자 자리의 가중치를 곱한다.
		// 이후 10으로 나머지 연산을 진행하여 결과가 0이면 i번째 요소가 훼손된 숫자이다.
		if ((Sum + i * MissingWeight) % 10 == 0)
			std::cout << i << std::endl;
	}

	return 0;
}