#include <iostream>
#include <algorithm>
#include <vector>
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

    vector <pair<int, int>> Nums(N, { 0, 0 });

    for (int i = 0; i < N; ++i)
        cin >> Nums[i].first >> Nums[i].second;

    sort(Nums.begin(), Nums.end(), Compare);

    for (int i = 0; i < N; ++i)
    {
        cout << Nums[i].first << ' ' << Nums[i].second << '\n';
    }

    return 0;
}