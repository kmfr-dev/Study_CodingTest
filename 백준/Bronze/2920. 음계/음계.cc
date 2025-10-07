#include <iostream>

int main()
{
	// 정수형 배열 선언
	int Numchar[8] = { 0 };
	
	// ascending, descending, mixed를 
	// 구분할 플래그 bool 변수
	bool IsAscending = true;
	bool IsDescending = true;
	
	// 8번 입력을 받아 배열에 값을 바꿔준다.
	for (int i = 0; i < 8; ++i)
		std::cin >> Numchar[i];

	// 숫자를 비교하기 위한 변수
	int Temp = 0;
	// 7번 반복
	for (int i = 0; i < 7; ++i)
	{
		// i + 1 요소의 값을 Temp에 저장
		Temp = Numchar[i + 1];

		// Temp와 배열의 i번째 요소에 +-1을 더한값과 비교하여 플래그를 변경
		if (Temp != Numchar[i] + 1)
			IsAscending = false;
		if (Temp != Numchar[i] - 1)
			IsDescending = false;
	}

	// 플래그에 따라 문자열 출력
	if (IsAscending)
		std::cout << "ascending" << std::endl;
	else if (IsDescending)
		std::cout << "descending" << std::endl;
	else
		std::cout << "mixed" << std::endl;

	return 0;
}