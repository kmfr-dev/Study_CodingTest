#include <iostream>
#include <algorithm>
#include <vector>


int main()
{
	// 삼각형의 변의 길이가 담길 배열
	std::vector<int> Edge;
	Edge.resize(3);

	// 무한루프
	while (true)
	{
		for (int j = 0; j < Edge.size(); ++j)
		{
			// 삼각형의 변의 길이를 담을 변수
			int Num;
			// 변의 길이를 입력 받아 준다.
			std::cin >> Num;
			// 벡터 j번째에 저장
			Edge[j] = Num;
		}

		// 세변 모두 0이면 break
		if (0 == Edge[0] && 0 == Edge[1] && 0 == Edge[2])
			break;

		// 배열 오름차순 정렬
		std::sort(Edge.begin(), Edge.end());

		// 변 A의 길이
		int A = Edge[0];
		// 그대로 제곱
		A *= A;
		// 변 B의 길이
		int B = Edge[1];
		// 그대로 제곱
		B *= B;
		// 변 C의 길이
		int C = Edge[2];
		// 그대로 제곱
		C *= C;

		// A제곱 + B제곱의 결과가 C와 같은지 판단한다.

		// 같다면 직각 삼각형이므로 문자열 right 출력
		if (A + B == C)
			std::cout << "right" << std::endl;

		// 다르다면 직각 삼각형이 아니므로 wrong 출력
		else
			std::cout << "wrong" << std::endl;
	}

	return 0;
}