#include <iostream>
#include <vector>

int main()
{
	// 카드의 갯수와 목표 숫자를 저장할 변수
	int CardNumber, GoalNumber= { 0 };
	// 입력을 받는다,
	std::cin >> CardNumber >> GoalNumber;

	// 카드 갯수 만큼 벡터의 크기를 설정
	std::vector<int> CardArray(CardNumber);
	
	// 입력을 받아 배열의 요소에 넣어준다.
	for (int i = 0; i < CardNumber; ++i)
		std::cin>> CardArray[i];

	// 합산 결과 출력용 변수
	int BestSum = { 0 };

	for (int i = 0; i < CardNumber; ++i)
	{
		for (int j = i + 1; j < CardNumber; ++j)
		{
			for (int k = j + 1; k < CardNumber; ++k)
			{
				// 배열의 i, j, k번째 요소를 더한다.
				int Result = CardArray[i] + CardArray[j] + CardArray[k];
				
				// 만약 합산 결과가 목표 숫자보다 작거나 같고
				// 현재 합산 결과보다 크다면 
				if (Result <= GoalNumber && BestSum < Result)
				{
					// 합산 결과를 갱신해준다.
					BestSum = Result;
				}
			}
		}
	}

	// 목표 숫자와 가장 가까운 결과 출력
	std::cout << BestSum << std::endl;

	return 0;
}