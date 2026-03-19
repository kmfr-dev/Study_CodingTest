#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    cin >> M;

    bool s[21] = { false };

    while (M--)
    {
        string str;
        int Num;

        cin >> str;

        if (str == "add")
        {
            cin >> Num;
            s[Num] = true;
        }

        else if (str == "check")
        {
            cin >> Num;
            cout << s[Num] << '\n';
        }

        else if (str == "remove")
        {
            cin >> Num;
            s[Num] = false;
        }

        else if (str == "toggle")
        {
            cin >> Num;
            s[Num] = !s[Num];
        }

        else if (str == "empty")
            fill(s, s + 21, false);

        else if (str == "all")
            fill(s, s + 21, true);
    }

    return 0;
}