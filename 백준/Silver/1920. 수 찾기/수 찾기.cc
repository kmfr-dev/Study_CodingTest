#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool FindTarget(const vector<int>& _TargetVec, int _Num)
{
    int StartIndex = 0;
    int EndIndex = _TargetVec.size() - 1;
    int MidIndex = (StartIndex + EndIndex) / 2;
    
    while(StartIndex <= EndIndex)
    {
        if(_TargetVec[MidIndex] == _Num)
            return true;
        
        if(_TargetVec[MidIndex] > _Num)
            EndIndex = MidIndex - 1;
        if(_TargetVec[MidIndex] < _Num)
            StartIndex = MidIndex + 1;
        
        MidIndex = (StartIndex + EndIndex) / 2;
    }
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N;
    
    vector<int> A(N, 0);
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    
    sort(A.begin(), A.begin() + N);
    
    cin >> M;
    
    for(int i = 0; i < M; ++i)
    {
        int Num;
        cin >> Num;
        
        cout << FindTarget(A ,Num) << '\n';
    }
    
    return 0;
}