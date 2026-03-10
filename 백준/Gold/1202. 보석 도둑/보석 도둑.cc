#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    
    vector<pair<int, int>> vec(N, {0, 0});
    for(int i = 0; i < N; ++i)
        cin >> vec[i].second >> vec[i].first;
    
    sort(vec.begin(), vec.end());
    
    multiset<int> bags;
    
    for(int i = 0; i < K; ++i)
    {
        int Num;
        cin >> Num;
        bags.insert(Num);
    }
        
    long long Total = 0;
    
    for(int i = N - 1; i >= 0; --i)
    {
        int M,V;
        tie(V, M) = vec[i];
        
        auto it = bags.lower_bound(M);
        if(it == bags.end())
            continue;
        
        Total += V;
        bags.erase(it);
    }
    
    cout << Total;
    
    return 0;
}