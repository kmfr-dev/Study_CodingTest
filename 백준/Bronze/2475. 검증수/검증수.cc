#include <iostream>
#include <vector>

int main()
{
    // Int형 백터 선언
    std::vector<int> UniqueIDs;
    
    // 입력받을 5개의 정수 변수 선언
    int A, B, C, D, E;
    
    // 입력을 받는다.
    std::cin >> A >> B >> C >> D >> E;

    // 벡터에 저장
    UniqueIDs.emplace_back(A);
    UniqueIDs.emplace_back(B);
    UniqueIDs.emplace_back(C);
    UniqueIDs.emplace_back(D);
    UniqueIDs.emplace_back(E);

    // 최종적으로 출력할 결과 변수 선언
    int Result = 0;
    // 벡터의 size만큼 반복
    for (int i = 0; i < UniqueIDs.size(); ++i)
    {
        // 요소에 있는 정수를 제곱하여 저장
        UniqueIDs[i] *= UniqueIDs[i];
        // 결과 변수에 더한다.
        Result += UniqueIDs[i];
    }

    // 결과 변수 나머지 연산
    Result %= 10;

    // 최종 결과 출력
    std::cout << Result << std::endl;

    return 0;
}