#include <iostream>

void Print(int _Score)
{
    // 기본 등급 문자는 F로 설정
    char Grade = 'F';

    // 100보다 작거나 같고 90보다 크거나 같을 때 A등급
    if (100 >= _Score && 90 <= _Score)
        Grade = 'A';
    // 89보다 작거나 같고, 80보다 크거나 같을 때 B등급
    else if (89 >= _Score && 80 <= _Score)
        Grade = 'B';
    // 79보다 작거나 같고, 70보다 크거나 같을 때 C등급
    else if (79 >= _Score && 70 <= _Score)
        Grade = 'C';
    // 69보다 작거나 같고, 60보다 크거나 같을 때 B등급
    else if (69 >= _Score && 60 <= _Score)
        Grade = 'D';

    // 등급 출력
    std::cout << Grade << std::endl;
}

int main()
{
    // 정수 변수 Num 선언
    int Score;

    // 입력을 받는다.
    std::cin >> Score;

    // 넘겨준 정수에 따라 등급을 출력하는 함수 호출
    Print(Score);

    return 0;
}