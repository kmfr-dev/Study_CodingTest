#include <iostream>
#include <vector>

int main()
{
	// 과목 갯수를 저장할 변수
	int Number = { 0 };
	// 입력을 받는다.
	std::cin >> Number;

	// 과목 점수를 저장할 벡터
	std::vector<int> SubjectScores(Number);
	
	// 제일 높은 수를 저장할 변수
	int BestNumber = { 0 };
	// 벡터의 크기만큼 반복
	for (int i = 0; i < SubjectScores.size(); ++i)
	{
		// 입력을 받아 과목 점수를 저장한다.
		std::cin >> SubjectScores[i];
		// 현재 높은 수보다 벡터의 i번째 요소가 크다면 갱신
		if (BestNumber < SubjectScores[i])
			BestNumber = SubjectScores[i];
	}

	// 각 점수의 합산을 저장할 변수
	float Sum = { 0.f };
	// 벡터의 크기 만큼 반복
	for (int i = 0; i < SubjectScores.size(); ++i)
	{
		// 현재요소 / 최대값 연산후 결과에 100을 곱해서 합산해준다.
		Sum += (SubjectScores[i] / static_cast<float>(BestNumber)) * 100;
	}

	// 평균을 구한다.
	Sum = Sum / Number;
	// 구한 평균을 출력
	std::cout << Sum << std::endl;

	return 0;
}