#include <iostream>

int main()
{
    // 정수 변수 Num 선언
    int Num;

    // 입력을 받는다.
    std::cin >> Num;

    // 입력 받은 만큼 반복 및 출력
    for (int i = 1; i <= Num; ++i)
        std::cout << i << "\n";


    return 0;
}