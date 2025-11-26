#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<int> Q;

    int N;
    cin >> N;

    while (N--)
    {
        string s;
        cin >> s;

        if (s == "push")
        {
            int Num;
            cin >> Num;
            Q.push(Num);
        }

        else if (s == "pop")
        {
            if (Q.empty())
                cout << -1 << "\n";
            else
            {
                cout << Q.front() << "\n";
                Q.pop();
            }
        }

        else if (s == "size")
        {
            cout << Q.size() << "\n";
        }

        else if (s == "empty")
        {
           cout << Q.empty() << "\n";
        }

        else if (s == "front")
        {
            if (Q.empty())
                cout << -1 << "\n";
            else
                cout << Q.front() << "\n";
        }

        else
        {
            if (Q.empty())
                cout << -1 << "\n";
            else
                cout << Q.back() << "\n";
        }
    }

    return 0;
}