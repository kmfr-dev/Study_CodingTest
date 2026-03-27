#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // K : 1 ~ 10,000
    // N : 1 ~ 1,000,000
    // K <= N
    int K, N;
    cin >> K >> N;

    vector<int> line(K, 0);
    for (int i = 0; i < K; ++i)
        cin >> line[i];

    sort(line.begin(), line.end());

    long long left = 1;
    long long right = line[K - 1];

    while (left <= right)
    {
        long long mid = (left + right) / 2;

        long long count = 0;
        for (int i = 0; i < K; ++i)
            count += line[i] / mid;

        if (count >= N)
            left = mid + 1;
        else
            right = mid - 1;
    }

    cout << right;

    return 0;
}