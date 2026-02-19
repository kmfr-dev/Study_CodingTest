#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Compare(pair<int, int> A, pair<int, int> B)
{
    if (A.second == B.second)
    {
        return A.first < B.first;
    }

    return A.second < B.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    if (N == 1)
    {
        cout << 1;
        return 0;
    }

    vector<pair<int, int>> Meetings(N + 5, { 0, 0 });

    for (int i = 1; i <= N; ++i)
    {
        int Start, End;
        cin >> Start >> End;
        Meetings[i] = make_pair(Start, End);
    }

    sort(Meetings.begin() + 1, Meetings.begin() + N + 1, Compare);

    int Total = 1;
    pair<int, int> Cur = Meetings[1];
    for (int i = 1; i < N; ++i)
    {
        if (Cur.second <= Meetings[i + 1].first)
        {
            Cur = Meetings[i+1];
            ++Total;
        }
    }
    
    cout << Total;

    return 0;
}