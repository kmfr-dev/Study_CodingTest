#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;

    while (N--)
    {
        int x;
        cin >> x;

        if (x == 0)
        {
            if (queue.empty())
                cout << 0 << '\n';

            else
            {
                pair<int, int> cur = queue.top();
                cout << cur.second << '\n';
                queue.pop();
            }
        }

        else
        {
            queue.push({ abs(x), x });
        }
    }

    return 0;
}