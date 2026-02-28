#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> origin(N + 5, 0);
    vector<long long> temp;

    for (int i = 0; i < N; ++i)
        cin >> origin[i];

    sort(origin.begin(), origin.begin() + N);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            temp.emplace_back(origin[i] + origin[j]);
    }

    sort(temp.begin(), temp.end());

    for (int i = N - 1; i >= 0; --i)
    {
        for (int j = 0; j < N - 1; ++j)
        {
            long long target = origin[i] - origin[j];
            auto it = lower_bound(temp.begin(), temp.end(), target);

            if (it != temp.end() && *it == target)
            {
                cout << origin[i];
                return 0;
            }
        }
    }

    return 0;
}