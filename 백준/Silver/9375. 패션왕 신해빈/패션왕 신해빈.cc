#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        map<string, set<string>> m;
        
        int Num;
        cin >> Num;

        for (int i = 0; i < Num; ++i)
        {
            string Wear, Parts;
            cin >> Wear >> Parts;

            m[Parts].insert(Wear);
        }

        int Total = 1;
        for (auto It = m.begin(); It != m.end(); ++It)
            Total *= It->second.size() + 1;

        Total -= 1;
        cout << Total << '\n';
    }

    return 0;
}