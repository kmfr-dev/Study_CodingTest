#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> Tiles(N + 1, 0);

    Tiles[1] = 1;
    Tiles[2] = 2;

    for (int i = 3; i <= N; ++i)
        Tiles[i] = (Tiles[i - 2] + Tiles[i - 1]) % 10007;

    cout << Tiles[N];

    return 0;
}