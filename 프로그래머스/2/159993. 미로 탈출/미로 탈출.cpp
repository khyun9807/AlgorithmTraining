#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

typedef pair<int, int> pii;

const int dx[4] = {-1, 1, 0, 0};  // 상하좌우
const int dy[4] = {0, 0, -1, 1};

int bfs(const vector<string>& maps, pii start, char target) {
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    deque<pair<pii, int>> q;  // ((x, y), dist)

    q.push_back({start, 0});
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        auto [cur, dist] = q.front(); q.pop_front();
        int x = cur.first;
        int y = cur.second;

        if (maps[x][y] == target) return dist;

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (visited[nx][ny]) continue;
            if (maps[nx][ny] == 'X') continue;

            visited[nx][ny] = true;
            q.push_back({{nx, ny}, dist + 1});
        }
    }

    return -1;  // target에 도달할 수 없음
}

int solution(vector<string> maps) {
    pii start, lever, exit;

    // 위치 찾기
    for (int i = 0; i < maps.size(); ++i) {
        for (int j = 0; j < maps[0].size(); ++j) {
            if (maps[i][j] == 'S') start = {i, j};
            else if (maps[i][j] == 'L') lever = {i, j};
            else if (maps[i][j] == 'E') exit = {i, j};
        }
    }

    int toLever = bfs(maps, start, 'L');
    if (toLever == -1) return -1;

    int toExit = bfs(maps, lever, 'E');
    if (toExit == -1) return -1;

    return toLever + toExit;
}