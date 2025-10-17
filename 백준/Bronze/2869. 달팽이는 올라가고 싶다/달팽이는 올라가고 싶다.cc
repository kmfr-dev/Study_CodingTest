#include <iostream>

int main()
{
	// 정수 A, B, V
	int A, B, V = { 0 };
	// 입력을 받는다.
	std::cin >> A >> B >> V;

	// 최종 몇일이 걸렸는지 계산할 정수
	// 남은 거리 = V (목표) - B (내려가는 높이)	
	// 올림 처리를 위해 - 1

	// A(올라가는 높이) - B (내려가는 높이)를 연산하여 
	// 남은거리를 나누면 필요한 일 수가 나온다. 
	// 마지막 날도 포함하기 위해 + 1
	int ResultDay = (V - B - 1) / (A - B) + 1;

	std::cout << ResultDay << std::endl;
}