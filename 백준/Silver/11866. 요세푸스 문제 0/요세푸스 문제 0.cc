#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    queue<int> Q;
    for (int i = 1; i <= N; ++i)
        Q.push(i);

    vector<int> Num;

    int Count = 1;
    while (!Q.empty())
    {
        int Cur = Q.front();

        if (Count == K)
        {
            Q.pop();
            Count = 1;
            Num.push_back(Cur);
        }
        else
        {
            Q.pop();
            Q.push(Cur);
            ++Count;
        }
    }

    cout << '<';
    for (int i = 0; i < N - 1; ++i)
        cout << Num[i] << ", ";
    cout << Num[N - 1] << '>';

    return 0;
}