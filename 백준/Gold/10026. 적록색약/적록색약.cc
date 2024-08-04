#include <iostream>
#include <vector>
using namespace std;

int N;
vector<string> grid;
vector<vector<bool>> visited;

// 상, 하, 좌, 우 방향 벡터
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y, char color, bool color_blind) {
    visited[x][y] = true;

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny]) {
            if (color_blind) {
                // 적록색약인 경우 R과 G를 동일하게 처리
                if ((color == 'R' || color == 'G') && (grid[nx][ny] == 'R' || grid[nx][ny] == 'G')) {
                    dfs(nx, ny, color, color_blind);
                } else if (color == grid[nx][ny]) {
                    dfs(nx, ny, color, color_blind);
                }
            } else {
                // 적록색약이 아닌 경우
                if (color == grid[nx][ny]) {
                    dfs(nx, ny, color, color_blind);
                }
            }
        }
    }
}

int countRegions(bool color_blind) {
    visited.assign(N, vector<bool>(N, false));
    int count = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!visited[i][j]) {
                dfs(i, j, grid[i][j], color_blind);
                ++count;
            }
        }
    }

    return count;
}

int main() {
    cin >> N;
    grid.resize(N);

    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
    }

    int normal = countRegions(false);
    int colorBlind = countRegions(true);

    cout << normal << " " << colorBlind << endl;
    return 0;
}