#include <iostream>

// 팩토리얼 계산 함수
int Factorial(int Number)
{
	int Result = 1;
    for (int i = 1; i <= Number; ++i)
		Result *= i;

	return Result;
}

int main()
{
	int N, K = { 0 };
	std::cin >> N >> K;

    // 이항 계수를 계산하여 출력한다.
	int Result = Factorial(N) / (Factorial(K) * Factorial(N - K));
	std::cout << Result << std::endl;

	return 0;
}