#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> Person(N, { 0, 0 });
    vector<int> vec(N, 0);

    for (int i = 0; i < N; ++i)
        cin >> Person[i].first >> Person[i].second;

    for (int i = 0; i < N; ++i)
    {
        int Count = 0;
        pair<int, int> CurPerson = Person[i];

        for (int j = 0; j < N; ++j)
        {
            pair<int, int> SecondPerson = Person[j];

            if (SecondPerson.first > CurPerson.first &&
                SecondPerson.second > CurPerson.second)
            {
                ++Count;
            }
        }

        vec[i] = Count + 1;
    }

    for (int i = 0; i < N; ++i)
        cout << vec[i] << ' ';

    return 0;
}