#include <iostream>
#include <cmath>

int main()
{
	// 참가자 수, 티셔츠와 펜의 묶음
	int Person, T, P;
	// 입력을 받는다.
	std::cin >> Person;

	// 사이즈 별 갯수를 담을 배열에 입력을 받아 저장한다.
	int sizes[6] = { 0 };
	for (int i = 0; i < 6; ++i)
		std::cin >> sizes[i];

	// 최소 묶음 주문수를 저장할 변수
	int Result = 0;
	// 티셔츠와 펜의 묶음 수를 입력 받는다.
	std::cin >> T >> P;

	// 배열 크기만큼 반복하여 최소 묶음 주문 수를 구한다.
	// 신청자 수 나누기 참가자 수 연산 후, 올림을 진행하여 결과에 더한다.
	for (int i = 0; i < 6; ++i)
		Result += static_cast<int>(std::ceil((sizes[i] + T - 1) / T));

	// 최종적으로 최소로 주문해야하는 티셔츠 묶음 수를 출력한다.
	std::cout << Result << std::endl;
	
	// 참가자수 나누기 P 연산하여 나온 값이 
	// 주문할 수 있는 최대 묶음 수 이므로 연산 후 출력한다.
	std::cout << Person / P << " ";

	// 참가자수를 P로 나눈다음 나머지가 
	// 펜을 한자루씩 몇개 주문하는 지를 출력한다.
	std::cout << Person % P << std::endl;

	return 0;
}