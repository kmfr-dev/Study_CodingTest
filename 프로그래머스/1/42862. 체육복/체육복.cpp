#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    vector<int> Reallost;
    vector<int> RealReserve = reserve;
    
    for(int i = 0; i < lost.size(); ++i)
    {
        auto It = find(RealReserve.begin(), RealReserve.end(), lost[i]);
        
        // 찾았으면 지우기
        if(It != RealReserve.end())
            RealReserve.erase(It);
        else
            Reallost.push_back(lost[i]);        
    }
    
    // 여벌 체육복의 빌려준 여부
    vector<bool> IsUsed(RealReserve.size(), false);
    
    int answer = n - Reallost.size();
    
    for(int i = 0; i < Reallost.size(); ++i)
    {
        int curlost = Reallost[i];
        
        for(int j = 0; j < RealReserve.size(); ++j)
        {
            // 이미 빌려준 학생이면 건너뜀
            if(IsUsed[j])
                continue;
            
            // 여벌의 체육복을 가진 학생 +-1이 잃어버린 학생의 번호라면 빌려준다.
            if(RealReserve[j] == curlost - 1 || RealReserve[j] == curlost + 1)
            {
                IsUsed[j] = true;
                ++answer;
                break;
            }
                
        }
    }
    
    return answer;
}