#include <iostream>
#include <list>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string Str;
    std::cin >> Str;

    std::list<char> List;
    std::list<char>::iterator ListIt;

    for (int i = 0; i < Str.length(); ++i)
        List.emplace_back(Str[i]);
    
    auto it = List.end();

    int N;
    std::cin >> N;

    std::string Command;
    for (int i = 0; i < N; ++i)
    {
        std::cin >> Command;
        if (Command == "L" && it != List.begin())
            --it;
        if (Command == "D" && it != List.end())
            ++it;
        if (Command == "B" && it != List.begin())
        {
            --it;
            it = List.erase(it);
        }
        if (Command == "P")
        {
            char x;
            std::cin >> x;
            it = List.insert(it, x);
            ++it;
        }
    }

    for (auto it = List.begin(); it != List.end(); ++it)
        std::cout << *it;

    return 0;
}