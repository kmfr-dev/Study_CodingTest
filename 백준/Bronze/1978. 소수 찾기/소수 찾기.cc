#include <iostream>

int main()
{
	// N개의 자연수를 입력 받기 위해 변수 선언
	int N = { 0 };
	// 입력을 받는다.
	std::cin >> N;

	// 자연수를 저장할 변수와 소수의 갯수를 출력할 변수 선언
	int Number, Result = { 0 };

	// 소수인지 확인할 bool값
	bool IsPrime = false;
	// N번 반복
	for (int i = 0; i < N; ++i)
	{
		// 자연수를 입력받는다.
		std::cin >> Number;

		// 자연수가 1보다 클때만
		if (1 < Number)
		{
			// 먼저 소수여부를 true로 변경
			IsPrime = true;
			
			// 2부터 자연수까지 반복
			for (int j = 2; j < Number; ++j)
			{
				// 자연수와 j를 나머지 연산하여 0이면 
				// 나누어떨어지므로 소수 플래그를 변경하고 break
				if (Number % j == 0)
				{
					IsPrime = false;
					break;
				}
			}

			// 소수라면 결과값 1 증감
			if (IsPrime)
				++Result;
		}
	}

    // 결과 출력
	std::cout << Result << std::endl;

	return 0;
}