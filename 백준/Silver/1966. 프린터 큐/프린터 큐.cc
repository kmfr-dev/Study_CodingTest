#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    queue<int> Result;

    while (T--)
    {
        queue<pair<int, int>> Q;

        int N, Imp;
        cin >> N >> Imp;

        int Max = 0;
        for (int i = 0; i < N; ++i)
        {
            int Num;
            cin >> Num;
            Max = max(Max, Num);
            Q.push({ i, Num });
        }

        int Count = 0;

        while (!Q.empty())
        {
            pair<int, int> Cur = Q.front();
            Q.pop();

            if (Q.empty())
            {
                Result.push(++Count);
                break;
            }
            
            if (Cur.second < Max)
            {
                Q.push(Cur);
            }

            else
            {
                if (Cur.first == Imp)
                {
                    Result.push(++Count);
                    break;
                }
                else
                {
                    ++Count;

                    Max = 0;
                    queue<pair<int, int>> Temp = Q;

                    while (!Temp.empty())
                    {
                        Max = max(Max, Temp.front().second);
                        Temp.pop();
                    }
                }
            }
        }

    }


    while (!Result.empty())
    {
        cout << Result.front() << '\n';
        Result.pop();
    }

    return 0;
}