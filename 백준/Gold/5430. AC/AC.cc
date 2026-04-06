#include <iostream>
#include <deque>
#include <string>
using namespace std;

void PushNumber(deque<int>& _DQ, const string& _Str)
{
    string Num = "";
    for (char c : _Str)
    {
        if (isdigit(c))
            Num += c;
        else
        {
            if (!Num.empty())
            {
                _DQ.push_back(stoi(Num));
                Num = "";
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        string str;
        cin >> str;

        int length = 0;
        cin >> length;

        string arrstr;
        cin >> arrstr;

        deque<int> DQ;
        PushNumber(DQ, arrstr);

        bool IsReverse = false;
        bool IsError = false;
        for (int i = 0; i < str.length(); ++i)
        {
            if (str[i] == 'R')
                IsReverse = !IsReverse;

            else if (str[i] == 'D')
            {
                if (DQ.empty())
                {
                    cout << "error" << '\n';
                    IsError = true;
                    break;
                }
                else
                {
                    if (IsReverse)
                        DQ.pop_back();
                    else
                        DQ.pop_front();
                }
            }
        }

        if (IsError)
            continue;

        cout << "[";

        if (IsReverse)
        {
            for (auto It = DQ.rbegin(); It != DQ.rend(); ++It)
            {
                cout << *It;
                if (It + 1 != DQ.rend())
                    cout << ',';
            }
            
        }

        else
        {
            for (auto It = DQ.begin(); It != DQ.end(); ++It)
            {
                cout << *It;
                if (It + 1 != DQ.end())
                    cout << ',';
            }
        }

        cout << "]\n";

    }

    return 0;
}