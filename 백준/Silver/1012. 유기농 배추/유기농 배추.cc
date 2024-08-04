#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// BFS 탐색을 위한 방향 벡터: 상, 하, 좌, 우
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

// BFS 함수
void bfs(vector<vector<int>>& field, vector<vector<bool>>& visited, int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});  // 시작 위치 큐에 추가
    visited[x][y] = true;  // 시작 위치 방문 표시

    while (!q.empty()) {
        int cx = q.front().first;  // 현재 x 좌표
        int cy = q.front().second; // 현재 y 좌표
        q.pop();

        // 4방향 탐색
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];  // 다음 x 좌표
            int ny = cy + dy[i];  // 다음 y 좌표
            if (nx >= 0 && nx < field.size() && ny >= 0 && ny < field[0].size()) {  // 경계 검사
                if (field[nx][ny] == 1 && !visited[nx][ny]) {  // 배추가 있고, 방문하지 않은 곳이라면
                    visited[nx][ny] = true;  // 방문 처리
                    q.push({nx, ny});  // 큐에 추가
                }
            }
        }
    }
}

// 필요한 지렁이 수를 세는 함수
int countWorms(vector<vector<int>>& field) {
    int m = field.size();    // 배추밭의 가로 길이
    int n = field[0].size(); // 배추밭의 세로 길이
    vector<vector<bool>> visited(m, vector<bool>(n, false)); // 방문 여부를 기록할 2차원 벡터
    int worms = 0; // 필요한 지렁이 수

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (field[i][j] == 1 && !visited[i][j]) { // 배추가 있고 방문하지 않았다면
                bfs(field, visited, i, j); // 해당 배추 위치에서 BFS 실행
                worms++; // 지렁이 수 증가
            }
        }
    }

    return worms; // 계산된 지렁이 수 반환
}

int main() {
    int T;
    cin >> T; // 테스트 케이스 수 입력 받기

    while (T--) {
        int M, N, K;
        cin >> M >> N >> K; // 가로, 세로 길이와 배추 위치의 수 입력 받기

        vector<vector<int>> field(M, vector<int>(N, 0)); // 배추밭을 나타내는 2차원 벡터 초기화
        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y; // 배추 위치 입력 받기
            field[x][y] = 1; // 해당 위치에 배추 심기
        }

        cout << countWorms(field) << endl; // 지렁이 수 출력
    }

    return 0;
}