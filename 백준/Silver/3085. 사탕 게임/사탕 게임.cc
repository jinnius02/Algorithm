#include <iostream>
#include <algorithm> // max 함수 사용
using namespace std;

int N;
char board[50][50];

// 주어진 보드의 특정 행 또는 열에서 가장 긴 같은 색상의 사탕 수를 찾는 함수
int findLongestCandyLine() {
    int maxLength = 1;

    for (int i = 0; i < N; i++) {
        // 각 행과 열에 대해 연속된 최대 길이를 계산
        int rowLength = 1, colLength = 1;
        for (int j = 1; j < N; j++) {
            // 행 검사
            if (board[i][j] == board[i][j-1]) {
                rowLength++;
            } else {
                maxLength = max(maxLength, rowLength);
                rowLength = 1;
            }
            
            // 열 검사
            if (board[j][i] == board[j-1][i]) {
                colLength++;
            } else {
                maxLength = max(maxLength, colLength);
                colLength = 1;
            }
        }
        maxLength = max(maxLength, max(rowLength, colLength));
    }

    return maxLength;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    int answer = 1;

    // 모든 가능한 인접 셀 쌍에 대해 교환을 시도하고, 그 결과로 가장 긴 사탕 줄을 찾음
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            // 행에 대한 교환
            swap(board[i][j], board[i][j+1]);
            answer = max(answer, findLongestCandyLine());
            swap(board[i][j], board[i][j+1]); // 원래대로 되돌림

            // 열에 대한 교환
            swap(board[j][i], board[j+1][i]);
            answer = max(answer, findLongestCandyLine());
            swap(board[j][i], board[j+1][i]); // 원래대로 되돌림
        }
    }

    cout << answer << endl;
    return 0;
}
