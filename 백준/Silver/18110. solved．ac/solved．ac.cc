#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    if (N == 0)
    {
        cout << 0;
        return 0;
    }

    vector<int> Nums(N, 0);

    int Total = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> Nums[i];
        Total += Nums[i];
    }

    sort(Nums.begin(), Nums.end());

    int Percent = (int)round(N * 0.15f);
    int Max = N - Percent;

    int Result = 0;
    for (int i = Percent; i < Max; ++i)
        Result += Nums[i];

    cout << (int)round((float)Result / (Max - Percent));

    return 0;
}