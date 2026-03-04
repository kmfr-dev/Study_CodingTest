#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_set<string> Persons;

    int N;
    cin >> N;

    while (N--)
    {
        string Name, Log;
        cin >> Name >> Log;

        if (Log == "enter")
            Persons.insert(Name);
        else
            Persons.erase(Name);
    }

    vector<string> Answer(Persons.begin(), Persons.end());

    sort(Answer.begin(), Answer.end(), greater<string>());

    for (auto& Str : Answer)
        cout << Str << '\n';


    return 0;
}