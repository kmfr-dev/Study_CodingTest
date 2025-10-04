#include <iostream>

void Print(int _Year)
{
    // 결과 변수 선언
    int Result = 0;

    // 인자로 넘어온 값을 4의 배수이면서,
    // 100의 배수가 아닐 때 or 400의 배수 일 때를 확인한다.
    if (_Year % 4 == 0 && (_Year % 100 != 0 || _Year % 400 == 0))
        Result = 1;

    // 0 or 1 출력
    std::cout << Result << std::endl;
}

int main()
{
    // 정수 변수 Num 선언
    int Year;

    // 입력을 받는다.
    std::cin >> Year;

    // 윤년의 여부를 출력하는 함수 호출
    Print(Year);

    return 0;
}