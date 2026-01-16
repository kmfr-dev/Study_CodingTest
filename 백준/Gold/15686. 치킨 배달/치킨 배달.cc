#include <bits/stdc++.h>
using namespace std;

int N, M;
int City[55][55];
vector<pair<int, int>> House;
vector<pair<int, int>> Chicken;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            cin >> City[i][j];
            if(City[i][j] == 1)
                House.emplace_back(i, j);
            if(City[i][j] == 2)
                Chicken.emplace_back(i, j);
        }
    }
    
    vector<int> brute(Chicken.size(), 1);
    fill(brute.begin(), brute.begin() + Chicken.size() - M, 0);
    int Answer = INT_MAX;
    do
    {
        int Dist = 0;
        for(auto H : House)
        {
            int Temp = INT_MAX;
            for(int i = 0; i < Chicken.size(); ++i)
            {
                if(brute[i] == 0)
                    continue;
                Temp = min(Temp, abs(Chicken[i].first - H.first) + abs(Chicken[i].second - H.second));
            }
            Dist += Temp;
        }
        
        Answer = min(Answer, Dist);
    }
    while(next_permutation(brute.begin(), brute.end()));
    
    cout << Answer;
    
    
    return 0;
}