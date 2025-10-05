#include <iostream>
#include <string>

int main()
{
	// 정수 Num 선언
	int Num;
	// 입력을 받는다.
	std::cin >> Num;

	// 결과 문자열
	std::string Result = "";
	
	// Num 만큼 반복
	for (int i = 0; i < Num; ++i)
	{
		// Num - i - 1 만큼 공백 출력
		for (int j = 0; j < Num - i - 1;++j)
			Result += " ";
		
		// 그 다음 별 출력
		for (int k = 0; k <= i; ++k)
			Result += "*";

		// 다음 반복 전에 개행
		Result += "\n";
	}

	// 결과 출력
	std::cout << Result << std::endl;

	return 0;
}