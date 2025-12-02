#include<bits/stdc++.h>
using namespace std;

int Arr[100002];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    fill(Arr, Arr + 100002, -1);
    
    int N, K;
    cin >> N >> K;
    Arr[N] = 0;
    
    queue<int> Q;
    Q.push(N); 
        
    while(Arr[K] == -1)
    {
        int CurVal = Q.front();
        Q.pop();
        
        for(int NextVal : {CurVal -1, CurVal+1, CurVal * 2})
        {
            // 유효한 인덱스인지 확인
            if(NextVal < 0 || NextVal > 100000)
                continue;
            
            // 이미 방문했으면 continue
            if(Arr[NextVal] != -1)
                continue;
            
            Arr[NextVal] = Arr[CurVal] +1;
            Q.push(NextVal);
        }
    }
    
    cout << Arr[K] << "\n";
    
    return 0;
}