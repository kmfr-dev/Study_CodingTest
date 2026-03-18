#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> Nums(N, 0);
    vector<int> Mode(8001, 0);

    int Total = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> Nums[i];
        Total += Nums[i];
        ++Mode[Nums[i] + 4000];
    }

    cout << (int)round((double)Total / N) << '\n';

    sort(Nums.begin(), Nums.end());

    cout << Nums[N / 2] << '\n';

    int Max = *max_element(Mode.begin(), Mode.end());
    vector<int> vec;
    for (int i = 0; i < 8001; ++i)
    {
        if (Mode[i] == Max)
            vec.push_back(i - 4000);
    }

    if (vec.size() >= 2)
        cout << vec[1] << '\n';
    else
        cout << vec[0] << '\n';

    cout << Nums[N - 1] - Nums[0] << '\n';


    return 0;
}