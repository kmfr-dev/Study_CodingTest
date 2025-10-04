#include <iostream>
#include <climits>

int main()
{
    int Num, Input;
    std::cin >> Num;
    
    int Best = -10000001;
    int Worst = 10000001;

    for (int i = 0; i < Num; ++i)
    {
        // 입력을 받는다.
        std::cin >> Input;

        // 입력을 받은 숫자를 비교하여
        // 최소값과 최대값을 갱신 해준다.

        if (Input > Best)
            Best = Input;

        if (Input < Worst)
            Worst = Input;
    }
    
    // 최소값과 최대값 출력
    std::cout << Worst << " " << Best << std::endl;

    return 0;
}