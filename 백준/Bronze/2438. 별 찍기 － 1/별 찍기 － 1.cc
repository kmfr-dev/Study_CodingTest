#include <iostream>
#include <string.h>

int main()
{
    // 정수 Num 선언
    int Num;

    // 입력을 받는다.
    std::cin >> Num;

    // 문자열 String 변수 선언.
    std::string Star = "";

    // Num만큼 반복
    for (int i = 0; i < Num; ++i)
    {
        // 내부 반복문에서는 별 문자열을 추가
        for (int j = 0; j < i + 1; ++j)
            Star += "*";
        
        // 별 출력
        std::cout << Star << std::endl;
        // 다음 반복문을 시작하기 전에 문자열을 빈 문자열로 초기화
        Star = "";
    }

    return 0;
}