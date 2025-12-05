#include<bits/stdc++.h>
using namespace std;

int Dist[1000002];

// F층, 위치 G, 현재 S,
    
// 위로 U층으로가는 버튼, 아래로 D층으로가는 버튼
    
// G층에 도착하려면 버튼을 적어도 몇번 눌러야 하는지, 만약
// G층에 갈 수 없다면 use the stairs를 출력

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    fill(&Dist[0], &Dist[0] + 1000002, -1);
    
    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;
    
    queue<int> Q;
    
    Dist[S] = 0;
    Q.push(S);
    
    while(!Q.empty())
    {
        int Cur = Q.front();
        Q.pop();
        
        if(Cur == G)
            break;
        
        int NextUp = Cur + U;
        int NextDown = Cur - D;
        
        // 만약 꼭대기층을 벗어나지않고 방문하지 않았다면
        if(NextUp <= F && Dist[NextUp] == -1)
        {
            Dist[NextUp] = Dist[Cur] + 1;
            Q.push(NextUp);
        }
        
        if(NextDown >= 1 && Dist[NextDown] == -1)
        {
            Dist[NextDown] = Dist[Cur] + 1;
            Q.push(NextDown);
        }
    }
    
    if(Dist[G] == -1)
        cout << "use the stairs";
    else
        cout << Dist[G];
    
    return 0;
}