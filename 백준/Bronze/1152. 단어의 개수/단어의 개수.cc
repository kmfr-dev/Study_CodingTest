#include <iostream>
#include <string>

int main()
{
	std::string InputString = "";
	std::getline(std::cin, InputString);

	int Result = 0;
	for (int i = 0; i < InputString.length(); ++i)
	{
		// 0번 인덱스 공백일 경우 예외처리
		if (i == 0 && InputString[i] == ' ')
			continue;
		
		// i가 만약 문자열 길이 - 1만큼 도달했다면
		// 단어 갯수 1회 증감
		if (i == InputString.length() - 1)
		{
			++Result;
			continue;
		}

		// 공백이 나오면 단어 갯수 1회 증감
		if (InputString[i] == ' ')
		{
			++Result;
			continue;
		}
	}

	std::cout << Result << std::endl;

	return 0;
}