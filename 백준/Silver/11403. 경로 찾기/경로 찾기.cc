#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> vec(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            cin >> vec[i][j];
    }

    for (int k = 0;  k < N; ++k)
    {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
            {
                if (vec[i][k] && vec[k][j])
                    vec[i][j] = 1;
            }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            cout << vec[i][j] << ' ';
        cout << '\n';
    }


    return 0;
}