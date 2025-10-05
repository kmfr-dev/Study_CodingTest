#include <iostream>

int main()
{
    int Num, R;
    std::cin >> Num;
    
    std::string InputString = "";
    std::string ResultString = "";
    for (int i = 0; i < Num; ++i)
    {
        std::cin >> R;
        std::cin >> InputString;

        for (int j = 0; j < InputString.length(); ++j)
        {
            for(int E = 0; E < R; ++E)
                ResultString += InputString[j];
        }

        
        std::cout << ResultString << std::endl;
        ResultString = "";
    }

    return 0;
}