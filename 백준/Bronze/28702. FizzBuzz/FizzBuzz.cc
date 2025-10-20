#include <iostream>
#include <string>
#include <cctype>

// 인자로 넘어온 문자열이 숫자인지를 판별하는 함수
bool IsNumber(const std::string& str) 
{
    for (const char& c : str) 
    {
        // 만약 하나의 문자라도 숫자가 아니라면 return false
        if (false == std::isdigit(c)) 
            return false;
    }
    
    return true;
}

int main() 
{
    int LastNum = { 0 };
    // 3번 반복
    for (int i = 1; i <= 3; ++i)
    {
        // 문자열을 입력 받는다.
        std::string Input = { "" };
        std::cin >> Input;

        // 만약 문자열이 숫자라면 변수에 저장
        if (true == IsNumber(Input))
            LastNum = std::stoi(Input);
        // 아니라면 숫자를 저장하는 변수 증감
        else
            ++LastNum;
    }
    
    // 마지막 숫자를 한 번더 증감한다.
    ++LastNum;

    // 배수여부를 판단하여 문자열 or 숫자 출력
    if (LastNum % 3 == 0 && LastNum % 5 == 0)
        std::cout << "FizzBuzz" << std::endl;
    else if (LastNum % 3 == 0)
        std::cout << "Fizz" << std::endl;
    else if (LastNum % 5 == 0)
        std::cout << "Buzz" << std::endl;
    else
        std::cout << LastNum << std::endl;

    return 0;
}
