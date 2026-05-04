#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    // 맵 초기화: n x m 크기의 벡터를 0으로 초기화
    vector<vector<int>> map(n, vector<int>(m, 0));
    // 시작점 (0, 0)에서 시작할 수 있는 경로 수는 1
    map[0][0] = 1;

    // 웅덩이를 맵에 표시
    for(vector<int> v : puddles)
    {
        // 웅덩이를 -1로 설정 (v[1]-1, v[0]-1은 웅덩이의 위치)
        map[v[1] - 1][v[0] - 1] = -1;
    }
    
    // 맵을 순회하여 각 위치의 경로 수 계산
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            // 시작점은 이미 처리했으므로 건너뜀
            if(i == 0 && j == 0)
                continue;
            
            // 웅덩이는 건너뜀
            if(map[i][j] == -1)
                continue;
            
            int count = 0; // 현재 위치까지의 경로 수
            
            // 위쪽 위치에서 오는 경로 수 추가
            if(i - 1 >= 0 && map[i - 1][j] != -1)
            {
                count += map[i - 1][j];
            }
            // 왼쪽 위치에서 오는 경로 수 추가
            if(j - 1 >= 0 && map[i][j - 1] != -1)
            {
                count += map[i][j - 1];
            }
            
            // 현재 위치의 경로 수를 1,000,000,007로 나눈 나머지로 설정
            map[i][j] = count % 1000000007;
        }
    }
    
    // 맵의 오른쪽 아래 모서리(n-1, m-1)에서 경로 수 반환
    return map[n - 1][m - 1];
}