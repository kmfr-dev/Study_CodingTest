#include <iostream>
using namespace std;

long long Sum[100005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    Sum[0] = 0;
    for (int i = 1; i <= N; ++i)
    {
        cin >> Sum[i];
        Sum[i] = Sum[i - 1] + Sum[i];
    }

    int i = 0, j = 0;
    while (M--)
    {
        cin >> i >> j;
        
        cout << Sum[j] - Sum[i-1] << '\n';
    }

    return 0;
}