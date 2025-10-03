#include <iostream>
#include <string.h>

int main()
{
    // 정수 A, B 선언
    int A, B;
    
    // 입력을 받는다.
    std::cin >> A >> B;
    
    // 결과 문자열을 담을 string
    std::string Result = "";
 
    // 조건에 따라 문자열 변수에 문자를 할당해준다.
    if(A > B)
        Result = ">";    
    else if(A < B)
        Result = "<";    
    else
        Result = "==";      
    
    // 출력
    std::cout << Result << std::endl;
    
    return 0;
}