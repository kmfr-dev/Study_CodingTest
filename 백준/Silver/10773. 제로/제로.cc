#include <iostream>
#include <stack>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int K, N;
    std::cin >> K;
 
    std::stack<int> NumStack;
    
    int Sum = 0;
    for(int i = 0; i < K; ++i)
    {
        std::cin >> N;
       
        if(N == 0 && !NumStack.empty())
        {
            Sum -= NumStack.top();
            NumStack.pop();
        }
        else
        {
            Sum += N;
            NumStack.push(N);
        }
    }
    
    std::cout << Sum;
    
    return 0;
}