#include <iostream>
#include <string>

int main()
{
    // 정수 A, B, C
    int A, B, C;

    // A, B, C 입력 받기
    std::cin >> A >> B >> C;

    // 1. A + B - C 연산 수행
    int intResult = (A + B) - C;

    // 연산 결과 출력
    std::cout << intResult << std::endl;

    // 2. 정수 A를 문자열로 변환하여 초기화
    std::string StringResult = std::to_string(A);
    // 정수 B를 문자열로 변환하고 이어 붙임
    StringResult += std::to_string(B);
    // 문자열을 숫자로 변환하여 저장
    intResult = std::stoi(StringResult);
    // C를 뺀다.
    intResult -= C;

    // 연산 결과 출력
    std::cout << intResult << std::endl;


    return 0;
}