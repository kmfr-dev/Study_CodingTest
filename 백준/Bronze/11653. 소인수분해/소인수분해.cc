#include <iostream>
#include <vector>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> Result;

    for (int i = 2; i <= N;)
    {
        if (i * i > N)
            break;

        if (N % i == 0)
        {
            N /= i;
            Result.emplace_back(i);
        }
        else
            ++i;
    }

    if (N > 1)
        Result.emplace_back(N);

    for (int i = 0; i < Result.size(); ++i)
        cout << Result[i] << '\n';

    return 0;
}