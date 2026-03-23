#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    map<string, string> Sites;
    
    int N, M;
    cin >> N >> M;
    
    while(N--)
    {
        string Site, Password;
        cin >> Site >> Password;
        Sites[Site] = Password;
    }
    
    while(M--)
    {
        string Target;
        cin >> Target;
        
        if(Sites.end() != Sites.find(Target))
            cout << Sites[Target] << '\n';
    }
    
    return 0;
}