#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, bool> m;

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N + M; ++i)
    {
        bool Flag = false;
        string str;
        cin >> str;

        if (m.end() != m.find(str))
            Flag = true;

        m[str] = Flag;
    }

    vector<string> vec;

    int Total = 0;
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        if (true == it->second)
        {
            ++Total;
            vec.push_back(it->first);
        }
    }

    cout << Total << '\n';
    for (int i = 0; i < vec.size(); ++i)
        cout << vec[i] << '\n';

    return 0;
}