#include <iostream>
#include <vector>

void Print(int K, int N)
{
	std::vector<std::vector<int>> Apartment(K + 1, std::vector<int>(N + 1));

	// 0층에는 i호에 i명
	for (int i = 1; i <= N; ++i)
		Apartment[0][i] = i;
	// 모든층 1호에는 1명
	for (int j = 0; j <= K; ++j)
		Apartment[j][1] = 1;

	// 0층은 모두 초기화 되어있으므로 1층부터
	for (int i = 1; i <= K; ++i)
	{
		// 1호는 모두 초기화 되어있으므로 2호부터 반복
		// i층 j호에 이전층 현재호에 있는 인원수와 
		// 현재층 이전호에 있는 거주민 수를 합하여 저장
		for (int j = 2; j <= N; ++j)
			Apartment[i][j] = Apartment[i - 1][j] + Apartment[i][j - 1];
	}

	// K층 N호에 사는 거주민 수 출력
	std::cout << Apartment[K][N] << std::endl;
}

int main()
{
	// 케이스 갯수, 층, 호수를 저장할 변수
	int Case, K, N = { 0 };
	// 케이스를 입력 받는다.
	std::cin >> Case;

	for (int i = 0; i < Case; ++i)
	{
		// 층과 홋수를 입력 받는다.
		std::cin >> K >> N;
		// K층 N호의 거주민수를 출력하는 함수 호출
		Print(K, N);
	}
}