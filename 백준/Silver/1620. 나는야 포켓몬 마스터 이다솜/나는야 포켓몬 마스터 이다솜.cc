#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    unordered_map<string, int> map;
    vector<string> strs(N + 5);
    
    for(int i = 1; i <= N; ++i)
    {
        cin >> strs[i];
        map[strs[i]] = i;
    }
    
    while(M--)
    {
        string str;
        cin >> str;
        if(isdigit(str[0]))
            cout << strs[stoi(str)] << '\n';
        else
            cout << map[str] << '\n';
    }
    
    
    return 0;
}