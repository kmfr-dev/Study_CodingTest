#include <iostream>
#include <string>

int main()
{
	// 입력 받을 테스트 케이스 변수
	int Case;
	// 입력을 받는다.
	std::cin >> Case;

	// 테스트 케이스 마다 입력받을 문자열 변수
	std::string InputString = "";
	// 테스트 케이스 만큼 반복
	for (int i = 0; i < Case; ++i)
	{
		// 문자열을 입력받는다.
		std::cin >> InputString;
		
		// 결과 출력용 변수
		int Result = 0;
		// 증감 변수
		int Temp = 0;
		// 문자열 길이만큼 반복
		for (int j = 0; j < InputString.length(); ++j)
		{
			// 문자열에서 만약 j번째 문자가 O라면
			if (InputString[j] == 'O')
			{
				// 증감 변수를 +1 해주고
				// 결과 변수에 저장
				++Temp;
				Result += Temp;
			}
			// 아니라면 증감 변수를 0으로 만들어준다.
			else
				Temp = 0;
		}

		// 반복 끝나고 결과 출력
		std::cout << Result << std::endl;
		Temp = 0;
	}

	return 0;
}