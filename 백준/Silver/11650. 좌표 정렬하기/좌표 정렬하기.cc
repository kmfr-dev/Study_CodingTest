#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> Nums(N, { 0, 0 });

    for (int i = 0; i < N; ++i)
        cin >> Nums[i].first >> Nums[i].second;

    sort(Nums.begin(), Nums.end());

    for (int i = 0; i < N; ++i)
    {
        cout << Nums[i].first << ' ' << Nums[i].second << '\n';
    }

    return 0;
}