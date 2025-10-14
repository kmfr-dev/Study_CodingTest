#include <iostream>

int main()
{
	// 방 번호를 입력받기 위해 정수 선언
	int Num = { 0 };
	// 방 번호를 입력 받는다.
	std::cin >> Num;

	// 연산 결과를 저장할 변순
	int Sum = { 1 };
	// 최종 결과 출력용 변수
	int Result = { 1 };

	// 무한 루프
	while (true)
	{
		// 만약 방 번호보다 합산결과의 수가 크거나 같다면 break
		if (Sum >= Num)
			break;

		else
		{
			// 6 * 결과를 더해서 저장해준다.
			Sum += 6 * Result;
			// 결과 1증감
			++Result;
		}
	}

	// 최종 결과물 출력
	std::cout << Result << std::endl;

	return 0;
}