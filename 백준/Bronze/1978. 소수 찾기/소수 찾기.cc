#include <iostream>
#include <vector>
using namespace std;

bool Check(int num)
{
    if(num == 1)
        return false;
    
    for(int i = 2; i * i <= num; ++i)
    {
        if(num % i == 0)
            return false;
    }
    
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<int> vec(N + 1, 0);
   
    int Total = 0;
    for(int i = 1; i <= N; ++i)
    {
        cin >> vec[i];
        if(Check(vec[i]))
            ++Total;
    }
    
    cout << Total;
    
    return 0;
}