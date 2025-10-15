#include <iostream>
#include <string>

int main()
{
	while (true)
	{
		// 숫자를 문자열로 받기 위해 문자열 선언
		std::string NumberStr = { "" };
		// 입력을 받는다.
		std::cin >> NumberStr;

		// 문자열이 0이라면 리턴
		if (NumberStr == "0")
			return 0;
		
		// 팰린드롬 여부를 판단할 bool값
		bool IsPalindrome = true;
		// 문자열 길이
		int StrLength = NumberStr.length();

		// 문자열 길이 / 2 만큼 반복
		for (int i = 0; i < StrLength / 2; ++i)
		{
			// 문자가 서로 대칭이 아니라면 bool값을 변경 하고 반복문 종료
			if (NumberStr[i] != NumberStr[StrLength - 1 - i])
			{
				IsPalindrome = false;
				break;
			}
		}

		// 팰린드롬 여부에 따라 문자열 출력
		std::cout << (IsPalindrome ? "yes" : "no") << std::endl;
	}
	

	return 0;
}