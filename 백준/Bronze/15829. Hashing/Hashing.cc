#include <iostream>
#include <string>
#include <cmath>

const long long M = 1234567891;

int main()
{
	// 문자열 길이
	int L;
	// 길이를 입력 받는다.
	std::cin >> L;

	// 해시값을 계산할 문자열 선언 및 입력을 받는다.
	std::string String = { "" };
	std::cin >> String;

	// 문자열 길이 만큼 잘라서 다시 저장한다.
	String = String.substr(0, L);

	// 결과 출력용 변수
	long long Result = { 0 };
	// 제곱 계산을 위한 변수
	long long Pow = 1;
	// 문자열 길이만큼 반복
	for (int i = 0; i < String.length(); ++i)
	{
		// i번째 문자와 a를 빼주고 + 1을 해서 문자를 숫자로 매핑한다.
		int CurrentNumber = String[i] - 'a' + 1;
		// 문자 숫자값에 현재 31^i를 곱해서 결과에 더한다
		Result = (Result + CurrentNumber * Pow) % M;
		// 다음 반복 때 사용할 다음 제곱을 계산
		Pow = (Pow * 31) % M;
	}

	// 결과 출력
	std::cout << Result << std::endl;

	return 0;
}