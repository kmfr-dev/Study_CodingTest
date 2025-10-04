#include <iostream>
#include <vector>

int main()
{
    // Int형 벡터 선언
    std::vector<int> Numbers;

    int InputNumber = 0;
    for (int i = 0; i < 9; ++i)
    {    
        // 9개의 서로 다른 자연수를 입력을 받는다.
        std::cin >> InputNumber;
        // 벡터에 저장
        Numbers.emplace_back(InputNumber);
    }
    
    // 결과 인덱스 및 최댓값 변수 저장 변수
    int ResultIndex = 0;
    int Best = 0;

    for (int i = 0; i < Numbers.size(); ++i)
    {
        // 먼저 최대값을 i번째로 지정
        Best = Numbers[i];
        for (int j = 0; j < Numbers.size(); ++j)
        {
            // j번째가 현재 최대값보다 크다면
            if (Best < Numbers[j])
            {
                // 최대값을 j번째로 설정
                Best = Numbers[j];
                // 인덱스도 j번 + 1로 설정
                ResultIndex = j + 1;
            }
        }
    }

    // 최대값과 인덱스 출력
    std::cout << Best << std::endl;
    std::cout << ResultIndex << std::endl;

    return 0;
}