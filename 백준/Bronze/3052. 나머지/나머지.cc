#include <iostream>
#include <set>
#include <vector>

int main()
{
	// 요소를 저장할 벡터 선언 및 사이즈 설정
	std::vector<int> Numvec;
	Numvec.resize(10);

	// 벡터의 크기만큼 반복 및 입력을 받는다.
	for (int i = 0; i < Numvec.size(); ++i)
		std::cin >> Numvec[i];

	// 중복을 허용하지 않는 Set 선언
	std::set<int> NumSet;

	// 벡터의 크기만큼 반복 및 
	// i번째 요소를 나머지 연산하여 그 결과를 Set에 저장
	for (int i = 0; i < Numvec.size(); ++i)
		NumSet.insert(Numvec[i] % 42);
	
	// Set의크기가 곧 결과
	int Result = NumSet.size();

	// 결과를 출력
	std::cout << Result << std::endl;

	return 0;
}