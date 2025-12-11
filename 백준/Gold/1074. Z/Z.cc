#include <bits/stdc++.h>
using namespace std;

int Func(int N, int R, int C)
{
    // (1) Base Condition : 더이상 사분면으로 쪼개지지 않을 때 0을 리턴
    if(N == 0)
        return 0;
    
    // (2) 사분면으로 쪼갰을 때 격자 변의 길이를 계산
    int Half = 1 << (N - 1);
    
    // (3) 목표 지점이 어디인지 판별
 
    // (3 - 1) 왼쪽 상단 사각형에 방문해야 할 지점이 있을 경우
    if(R < Half && C < Half)
        return Func(N-1, R, C);
    // (3 - 2) 오른쪽 상단 사각형에 방문해야 할 지점이 있을 경우 
    if(R < Half && C >= Half)
        return Half * Half + Func(N-1, R, C-Half);
    // (3 - 3) 왼쪽 하단 사각형에 방문해야 할 지점이 있을경우
    if(R >= Half && C < Half)
        return 2 * Half * Half + Func(N-1, R-Half, C);
    // (3 - 4) 오른쪽 하단 사각형에 방문해야 할 지점이 있을 경우
    return 3 * Half * Half + Func(N-1, R-Half, C-Half);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, R, C;
    cin >> N >>  R >>  C;
    
    cout << Func(N, R, C);
    
    return 0;
}