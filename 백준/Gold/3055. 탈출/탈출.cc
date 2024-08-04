#include <iostream>
#include <queue>
using namespace std;

// 위치 정보를 담는 구조체
struct Position {
    int x, y;
};

int R, C;  // 지도의 행(R)과 열(C)의 수
char map[50][50];  // 지도 데이터를 저장하는 배열
queue<Position> waterQueue, hedgehogQueue;  // 물과 고슴도치의 위치를 저장하는 큐
int dx[4] = {0, 0, 1, -1};  // x 이동 방향 (위, 아래, 오른쪽, 왼쪽)
int dy[4] = {1, -1, 0, 0};  // y 이동 방향 (위, 아래, 오른쪽, 왼쪽)

// (x, y) 위치가 지도 범위 내에 있는지 검사하는 함수
bool inBounds(int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < C;
}

// BFS 알고리즘을 이용해 고슴도치가 비버의 굴로 이동하는 최소 시간을 계산하는 함수
int bfs() {
    int minutes = 0;  // 고슴도치가 이동하는 데 걸린 시간
    while (!hedgehogQueue.empty()) {
        // 물 확산 처리
        int waterSize = waterQueue.size();  // 현재 물의 위치 개수
        for (int i = 0; i < waterSize; i++) {
            auto w = waterQueue.front();
            waterQueue.pop();
            for (int d = 0; d < 4; d++) {
                int nx = w.x + dx[d], ny = w.y + dy[d];
                if (inBounds(nx, ny) && map[nx][ny] == '.') {
                    map[nx][ny] = '*';  // 빈 칸을 물로 채움
                    waterQueue.push({nx, ny});
                }
            }
        }

        // 고슴도치 이동 처리
        int hedgehogSize = hedgehogQueue.size();  // 현재 고슴도치의 위치 개수
        for (int i = 0; i < hedgehogSize; i++) {
            auto h = hedgehogQueue.front();
            hedgehogQueue.pop();
            for (int d = 0; d < 4; d++) {
                int nx = h.x + dx[d], ny = h.y + dy[d];
                if (inBounds(nx, ny)) {
                    if (map[nx][ny] == 'D') {  // 비버의 굴에 도착한 경우
                        return minutes + 1;
                    }
                    if (map[nx][ny] == '.') {  // 이동할 수 있는 빈 칸인 경우
                        map[nx][ny] = 'S';  // 고슴도치가 이동함
                        hedgehogQueue.push({nx, ny});
                    }
                }
            }
        }
        minutes++;  // 한 단계의 이동이 끝나면 시간 증가
    }
    return -1; // 비버의 굴로 이동할 수 없는 경우
}

int main() {
    cin >> R >> C;
    Position startHedgehog;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'S') {  // 고슴도치 시작 위치 설정
                startHedgehog = {i, j};
                hedgehogQueue.push(startHedgehog);
                map[i][j] = '.';  // 시작 위치를 빈 칸으로 변경
            } else if (map[i][j] == '*') {  // 물의 시작 위치 설정
                waterQueue.push({i, j});
            }
        }
    }

    int result = bfs();  // BFS 실행하여 결과 계산
    if (result == -1)
        cout << "KAKTUS";  // 이동 불가능한 경우 "KAKTUS" 출력
    else
        cout << result;  // 가능한 경우 최소 시간 출력

    return 0;
}