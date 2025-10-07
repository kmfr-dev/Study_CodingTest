#include <iostream>
#include <string>

int main()
{
	// 정수 A, B, C 선언
	int A, B, C;
	// 입력을 받는다.
	std::cin >> A >> B >> C;
	// A, B, C를 연산하여 연산결과를 문자열로 변환
	std::string ResultString = std::to_string(A * B * C);

	// 결과 출력용 변수
	int Result = 0;
	// 10번 반복
	for (int i = 0; i < 10; ++i)
	{
		// 문자열 길이만큼 반복
		for (int j = 0; j < ResultString.length(); ++j)
		{
			// 정수 i와 문자 비교, 
			// 이때, 아스키코드 '0'을 빼주고 비교한다.
			// 만약 i와 같다면 결과 변수 1회 증감
			if (i == (ResultString[j] - '0'))
				++Result;
		}

		// 결과 출력후 결과 0으로 초기화
		std::cout << Result << std::endl;
		Result = 0;
	}

	return 0;
}