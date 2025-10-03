#include <iostream>

void Print(int _Number)
{
    // 곱셈 결과를 저장할 변수
    int Result = 0;

    // 반복, 전체 반복 횟수는 한 번한다. 
    // 입력받은 N단만 출력하기 위해
    for (int i = _Number; i < _Number + 1; ++i)
    {
        // 1부터 시작, 9까지 반복
        for (int j = 1; j <= 9; ++j)
        {
            // 결과를 저장하고 출력한다.
            Result = i * j;
            std::cout << i << " * " << j << " = " << Result << std::endl;
        }
    }
}

int main()
{
    // 정수 Num 선언
    int Num;
    
    // 입력을 받는다.
    std::cin >> Num;

    // 구구단 출력 함수 호출
    Print(Num);

    return 0;
}