#include <iostream>
#include <string>

const int Max = 10001;
int Array[Max] = {};
int Pos = 0;

void Print(const std::string& String)
{
    if(String == "push")
    {
        int Num;
        std::cin >> Num;
        Array[Pos++] = Num;
    }
    if(String == "top")
        std::cout << (Pos == 0 ? -1 : Array[Pos - 1]) << "\n";
    if(String == "size")
        std::cout << Pos << "\n";   
    if(String == "pop")
    {
        if(Pos == 0)
            std::cout << -1 << "\n";
        else
        {
            std::cout << Array[Pos - 1] << "\n";
            --Pos;
        }
    }
    if(String == "empty")
    {
        std::cout << (Pos == 0 ? 1 : 0) << "\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;
    
    std::string String;
    for(int i = 0; i < N; ++i)
    {
        std::cin >> String;
        Print(String);
    }
    
    return 0;
}
