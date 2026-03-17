#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    multimap<int, string> map;

    for (int i = 0; i < N; ++i)
    {
        int age;
        string name;

        cin >> age >> name;

        map.insert({ age, name });
    }

    for (auto it = map.begin(); it != map.end(); ++it)
    {
        cout << it->first << ' ' << it->second << '\n';
    }

    return 0;
}