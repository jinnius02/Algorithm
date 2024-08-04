#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> map;
vector<vector<bool>> visited;
vector<int> houseCounts;

// 상하좌우 이동을 위한 배열
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

// DFS 함수
int dfs(int x, int y) {
    visited[x][y] = true;
    int count = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < N && map[nx][ny] == 1 && !visited[nx][ny]) {
            count += dfs(nx, ny);
        }
    }
    return count;
}

int main() {
    cin >> N;
    map.resize(N, vector<int>(N));
    visited.resize(N, vector<bool>(N, false));

    // 지도 정보 입력
    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < N; j++) {
            map[i][j] = line[j] - '0';
        }
    }

    // 모든 칸을 순회하면서 단지 확인
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && !visited[i][j]) {
                houseCounts.push_back(dfs(i, j));
            }
        }
    }

    // 단지 내 집의 수를 오름차순으로 정렬
    sort(houseCounts.begin(), houseCounts.end());

    // 출력
    cout << houseCounts.size() << endl;
    for (int count : houseCounts) {
        cout << count << endl;
    }

    return 0;
}