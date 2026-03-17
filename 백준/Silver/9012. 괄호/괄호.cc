#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    while (N--)
    {
        string str;
        cin >> str;

        stack<char> stack;

        bool Flag = true;

        for (int i = 0; i < str.length(); ++i)
        {
            char cur = str[i];

            if (cur == ')')
            {
                if (stack.empty())
                {
                    Flag = false;
                    break;
                }
                else
                {
                    char topchar = stack.top();
                    if (topchar == '(')
                        stack.pop();
                    else
                    {
                        Flag = false;
                        break;
                    }
                }
            }

            else
            {
                stack.push(cur);
            }
        }

        if (!Flag || !stack.empty())
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    }

    return 0;
}