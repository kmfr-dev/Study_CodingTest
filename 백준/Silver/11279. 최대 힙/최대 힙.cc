#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    priority_queue<int> queue;
    
    while(N--)
    {
        int x;
        cin >> x;
        
        if(x == 0)
        {
            if(queue.empty())
            {
                cout << 0 << '\n';                
            }
            
            else
            {
                int cur = queue.top();
                cout << cur << '\n';
                queue.pop();
            }
        }
        
        else
            queue.push(x);
    }
    
    return 0;
}