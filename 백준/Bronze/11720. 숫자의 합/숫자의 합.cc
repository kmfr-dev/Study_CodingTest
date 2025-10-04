#include <iostream>

void PrintStar(int _Number)
{
    // 결과를 출력할 변수
    int Result = 0;
    
    // 입력받을 숫자 100개에 대한 문자열
    std::string InputNumber = "";
    std::cin >> InputNumber;

    // 문자의 갯수만큼 반복
    // int 변수에 저장할때 '0'의 아스키 코드 값인 48을 빼면서 저장
    for (int i = 0; i < InputNumber.length(); ++i)
        Result += InputNumber[i] - '0';

    // 결과 출력
    std::cout << Result << std::endl;
}

int main()
{
    // 정수 변수 Num 선언
    int Num;

    // 입력을 받는다.
    std::cin >> Num;

    // 넘겨준 정수에 따라 숫자의 합을 출력하는 함수 호출
    PrintStar(Num);

    return 0;
}