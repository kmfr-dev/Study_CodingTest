#include <iostream>
#include <string>

int main()
{
	// 입력 받을 문자열 변수
	std::string InputString = "";
	// 입력을 받는다.
	std::cin >> InputString;

	// a 아스키 코드값은 10진수로 97,
	// z 아스키 코드값은 10진수로 122 이므로
	// 97에서 123까지 반복
	for (int i = 97; i < 123; ++i)
	{
		// 정수를 아스키 코드값으로 해석하여 문자로 변환
		char String = i;

		// 입력 받은 문자열에서 문자를 찾았는지 판단할 플래그 bool 값
		bool FindString = false;

		// 입력받은 문자열 길이만큼 반복
		for (int j = 0; j < InputString.length(); ++j)
		{
			// 변환한 문자와 입력받은 문자열의 j번째 문자와 비교,

			// 같고, 못찾았을 경우에만
			if (false == FindString && String == InputString[j])
			{
				// String이 j번째에 있다는 것이므로 j를 그대로 출력
				std::cout << j;
				// 출력 후 해당 문자는 찾았다는 의미 이므로 true로 바꿔준다.
				FindString = true;
				// 찾았으니 반복문 break
				break;
			}
		}

		// 만약 문자를 못찾았을 경우 -1을 출력
		if (false == FindString)
			std::cout << -1;

		// 다음 반복문 시작 전 공백 출력
		std::cout << " ";
	}

	return 0;
}