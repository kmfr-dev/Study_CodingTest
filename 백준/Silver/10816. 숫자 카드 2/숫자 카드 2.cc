#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int lowerIndex(const vector<int>& _cards, int _target, int len)
{
    int StartIndex = 0;
    int EndIndex = len;

    while (StartIndex < EndIndex)
    {
        int MidIndex = (StartIndex + EndIndex) / 2;
        if (_cards[MidIndex] >= _target)
            EndIndex = MidIndex;
        else
            StartIndex = MidIndex + 1;
    }

    return StartIndex;
}

int upperIndex(const vector<int>& _cards, int _target, int len)
{
    int StartIndex = 0;
    int EndIndex = len;

    while (StartIndex < EndIndex)
    {
        int MidIndex = (StartIndex + EndIndex) / 2;
        if (_cards[MidIndex] > _target)
            EndIndex = MidIndex;
        else
            StartIndex = MidIndex + 1;
    }

    return StartIndex;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N;

    vector<int> Cards(N + 1, 0);
    for (int i = 0; i < N; ++i)
        cin >> Cards[i];

    sort(Cards.begin(), Cards.begin() + N);

    cin >> M;

    while(M--)
    {
        int Num;
        cin >> Num;

        cout << upperIndex(Cards, Num, N) - lowerIndex(Cards, Num, N) << ' ';
    }

    return 0;
}