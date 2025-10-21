#include <iostream>
#include <string>
#include <vector>

int main()
{
	int Case = { 0 };
	std::cin >> Case;

	// string을 담는 벡터를 선언하고
	// Case만큼 벡터 크기를 잡아준다.
	std::vector<std::string> StrVec;
	StrVec.resize(Case);

	// Case만큼 입력을 받아 저장
	for (int i = 0; i < Case; ++i)
		std::cin >> StrVec[i];

	// 선택 정렬
	for (int i = 0; i < StrVec.size(); ++i)
	{
		int Best = i;
		// i + 1 부터 정렬 대상을 찾는다.
		for (int j = i + 1; j < StrVec.size(); ++j)
		{
			// 만약 Best번째 요소의 문자열 길이가
			// j번째 요소의 문자열 길이보다 클 경우 
			// Best를 j로 갱신
			if (StrVec[Best].length() > StrVec[j].length())
				Best = j;
				
			// 만약 Best번째 요소와 j번째 요소의 문자열 길이가 동일할 경우
			else if (StrVec[Best].length() == StrVec[j].length())
			{
				// 문자열 비교를 진행한다.
				int Result = StrVec[Best].compare(StrVec[j]);
				// 만약 결과가 더 크다면 
				// 사전에서 더 뒤에 있다는 의미이므로 
				// Best를 j로 갱신
				if (Result > 0)
					Best = j;
			}
		}

		// 반복 사이클을 돌때마다 정렬 진행
		std::string Temp = StrVec[i];
		StrVec[i] = StrVec[Best];
		StrVec[Best] = Temp;
	}

	// 정렬된 문자열 출력
	for (int i = 0; i < StrVec.size(); ++i)
	{
		// 첫번째 요소는 문자열을 반드시 출력,
		// 현재 요소의 문자열과 현재요소 - 1의 문자열이 다를때만 문자열 출력을 진행
		if(i == 0 || StrVec[i] != StrVec[i - 1])
			std::cout << StrVec[i] << std::endl;
	}

	return 0;

}
