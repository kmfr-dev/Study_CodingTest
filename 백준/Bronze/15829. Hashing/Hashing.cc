#include <iostream>
#include <string>
#include <cmath>

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
	// 문자열 길이만큼 반복
	for (int i = 0; i < String.length(); ++i)
	{
		int CurrentNumber = String[i] - 'a' + 1;
		int Sum = CurrentNumber * pow(31, i);
		Result = (Result + Sum) % 1234567891;
	}

	// 결과 출력
	std::cout << Result << std::endl;

	return 0;
}