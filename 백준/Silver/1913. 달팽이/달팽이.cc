#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, target;
    cin >> N >> target; // 사용자로부터 홀수 N과 위치를 찾을 숫자 target을 입력받음
    
    // N x N 크기의 2차원 벡터를 0으로 초기화
    vector<vector<int>> matrix(N, vector<int>(N, 0));
    int x = 0, y = 0; // 시작 좌표 초기화
    int dx[4] = {0, 1, 0, -1}; // x 방향 이동 패턴: 오른쪽, 아래, 왼쪽, 위
    int dy[4] = {1, 0, -1, 0}; // y 방향 이동 패턴: 오른쪽, 아래, 왼쪽, 위
    int direction = 0; // 시작 방향은 오른쪽

    // 달팽이 배열 채우기
    for(int i = N * N; i > 0; i--) {
        matrix[y][x] = i; // 현재 위치에 숫자 할당
        int nx = x + dx[direction];
        int ny = y + dy[direction];
        // 다음 위치가 범위를 벗어나거나 이미 숫자가 있으면 방향 전환
        if (nx < 0 || ny < 0 || nx >= N || ny >= N || matrix[ny][nx] != 0) {
            // 1. nx < 0 || ny < 0 => 계산된 다음 위치 nx나 ny가 배열의 범위를 벗어나는지 확인 -> 배열의 인덱스는 0부터 시작하므로 0 미만인 경우 유효X.
	        // 2. nx >= N || ny >= N => 배열의 범위를 벗어나는지 검사 -> N은 배열의 크기이므로 nx나 ny가 N 이상이면 범위를 벗어난 것임.
	        // 3. spiral[nx][ny] != 0 => 이미 숫자가 할당된 위치인지 확인 -> 배열을 채울 때 이미 할당된 칸에는 다시 숫자를 채우지 않도록 해야 하므로, 해당 위치의 값이 0이 아니면 이미 숫자가 채워진 것입임.
            
            direction = (direction + 1) % 4; // 방향을 시계 방향으로 전환
            nx = x + dx[direction];
            ny = y + dy[direction];
        }
        x = nx; // x 좌표 갱신
        y = ny; // y 좌표 갱신
    }

    // 달팽이 배열 출력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " "; // 각 행의 숫자 출력
        }
        cout << "\n";
    }

    // target 숫자의 위치 찾기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == target) {
                cout << i + 1 << " " << j + 1 << "\n"; // 1부터 시작하는 좌표 출력
                break;
            }
        }
    }

    return 0;
}