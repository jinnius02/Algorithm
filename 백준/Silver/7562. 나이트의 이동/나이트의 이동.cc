#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

// 나이트의 8가지 이동 가능 방향
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int bfs(int l, int startX, int startY, int endX, int endY) {
    vector<vector<bool>> visited(l, vector<bool>(l, false));
    queue<pair<pair<int, int>, int>> q; // 위치와 현재까지의 이동 횟수
    q.push({{startX, startY}, 0});
    visited[startX][startY] = true;

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        int x = current.first.first;
        int y = current.first.second;
        int count = current.second;

        if (x == endX && y == endY) return count; // 목표 위치 도달

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < l && ny >= 0 && ny < l && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({{nx, ny}, count + 1});
            }
        }
    }

    return -1; // 도달할 수 없는 경우 (이론상 발생하지 않음)
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, startX, startY, endX, endY;
        cin >> l >> startX >> startY >> endX >> endY;
        cout << bfs(l, startX, startY, endX, endY) << endl;
    }
    return 0;
}