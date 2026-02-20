#include <iostream>
#include <vector>
using namespace std;

vector<int> GetSieve(int Start, int End)
{
    vector<int> Primes;
    vector<bool> State(End + 1, true);
    
    State[1] = false;
    
    for(int i = 2; i * i <= End; ++i)
    {
        if(!State[i])
            continue;
        
        for(int j = i*i; j <= End; j+=i)
            State[j] = false;
    }
    
    for(int i = Start; i <= End; ++i)
    {
        if(State[i])
            Primes.emplace_back(i);
    }
    
    return Primes;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int M, N;
    cin >> M >> N;
    
    vector<int> Result = GetSieve(M, N);
    
    for(int i = 0; i < Result.size(); ++i)
        cout << Result[i] << '\n';
    
    return 0;
}