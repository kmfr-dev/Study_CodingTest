#include <iostream>
#include <string>

int main()
{
	// 자연수를 입력 받기 위해 변수 선언
	int N = { 0 };
	// 입력을 받는다.
	std::cin >> N;

	// 자릿수 최대합값을 계산한다.
	int NumDigit = 9 * std::to_string(N).length(); 
	// 자연수 N에서 최대합값을 빼면 최소 범위를 얻을 수 있다.
	int Min = N - NumDigit;
	
	// 결과 출력용 변수
	int Result = 0;

	// 최소 범위부터 N까지 반복
	for (int i = Min; i < N; ++i)
	{
		// 자릿수 합을 저장할 변수
		int Sum = 0;
		// i + i를하여 문자열로 변환
		std::string String = std::to_string(i);
		// 자릿수의 합을 정수로 저장
		for (char Str : String)
			Sum += Str - '0';

		// 만약 i + 자릿수의 합이 N과 같다면
		if ((i + Sum) == N)
		{
			// 결과에 i를 대입
			Result = i;
			break;
		}
	}

	// 결과 출력
	std::cout << Result << std::endl;

	return 0;
}