#include <iostream>
using namespace std;

// 해당 층과 호에 사는 사람의 수를 계산하는 함수
int numberOfResidents(int k, int n) {
    // 사람 수를 저장할 2차원 배열 선언
    int residents[15][15] = {0};

    // 0층 초기화: 0층 i호에는 i명이 산다.
    for (int i = 1; i <= 14; i++) {
        residents[0][i] = i;
    }

    // 1층부터 k층까지, 각 층에 대해 계산
    for (int floor = 1; floor <= k; floor++) {
        for (int room = 1; room <= n; room++) {
            // a층 b호의 거주민 수는 a-1층의 1호부터 b호까지의 사람들의 합
            for (int prevRoom = 1; prevRoom <= room; prevRoom++) {
                residents[floor][room] += residents[floor - 1][prevRoom];
            }
        }
    }
    // k층 n호에 살고 있는 사람 수 반환
    return residents[k][n];
}

int main() {
    int T, k, n;
    cin >> T; // 테스트 케이스의 수 입력

    while (T--) {
        cin >> k >> n; // 각 케이스에 대해 층(k)과 호(n) 입력 받기
        cout << numberOfResidents(k, n) << endl; // 계산된 거주민 수 출력
    }

    return 0;
}
