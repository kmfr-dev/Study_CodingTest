#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    multiset<long long> Q;

    int Case;
    cin >> Case;

    while (Case--)
    {
        int Num;
        cin >> Num;

        for (int i = 0; i < Num; ++i)
        {
            string str;
            cin >> str;

            long long Data;
            cin >> Data;

            if (str == "I")
            {
                Q.insert(Data);
            }

            else if (str == "D")
            {
                if (Q.empty())
                    continue;

                if (Data == -1)
                {
                    Q.erase(Q.begin());
                }
                else if (Data == 1)
                {

                    Q.erase(--Q.end());
                }
            }
        }

        if (Q.empty())
        {
            cout << "EMPTY\n";
        }
        else
        {
            cout << *(--Q.end()) << ' ' << *Q.begin() << '\n';
        }

        Q.clear();
    }

    return 0;
}