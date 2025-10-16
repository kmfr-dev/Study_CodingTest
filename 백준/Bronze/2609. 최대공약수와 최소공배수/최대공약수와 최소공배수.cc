#include <iostream>
#include <vector>

int main()
{
	// 두 개의 자연수를 받기 위해 변수 선언
	int A, B = { 0 };
	// 입력을 받는다.
	std::cin >> A >> B;

	// 최대 공약수를 저장할 변수
	int GCD = { 0 };
	// A만큼 반복
	for (int i = 1; i <= A; ++i)
	{
		// A와 B를 i로 나눠서 나머지가 0이면 
		// 공약수이므로 최대 공약수 갱신
		if (A % i == 0 && B % i == 0)
			GCD = i;
	}

	// A와 B의 최소 공배수를 구해준다.
	int LCM = (A * B) / GCD;
	
	// 최대 공약수와 최소 공배수 출력
	std::cout << GCD << "\n" << LCM << std::endl;

	return 0;
}