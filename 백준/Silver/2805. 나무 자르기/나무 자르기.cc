#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    vector<int> Tree(N, 0);
    for(int i = 0; i < N; ++i)
        cin >> Tree[i];
    
    sort(Tree.begin(), Tree.end());
    
    int left = 0;
    int right = Tree.back();
    
    int Answer = 0;
    
    while(left <= right)
    {
        int mid = (left + right) / 2;
        
        long long Sum = 0;
        for(int i = 0; i < N; ++i)
        {
            if(Tree[i] > mid)
                Sum += (Tree[i] - mid);
        }
        
        if(Sum >= M)
        {
            Answer = mid;        
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    
    cout << Answer;
    
    return 0;
}