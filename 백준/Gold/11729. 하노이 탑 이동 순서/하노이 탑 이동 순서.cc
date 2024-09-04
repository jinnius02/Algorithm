#include <iostream>
using namespace std;

// hanoi 함수는 재귀적으로 하노이 탑 문제를 해결합니다.
// n: 이동시킬 원판의 수
// start: 원판들이 현재 있는 장대
// end: 원판들을 옮길 목표 장대
// temp: 임시로 사용할 장대
void hanoi(int n, int start, int end, int temp) {
    // 기저 조건: 원판이 1개일 때는 바로 목표 장대로 옮깁니다.
    if (n == 1) {
        cout << start << " " << end << "\n";
    } else {
        // 가장 큰 원판을 제외한 n-1개를 temp 장대로 이동
        hanoi(n - 1, start, temp, end);
        // 가장 큰 원판을 목표 장대로 이동
        cout << start << " " << end << "\n";
        // temp 장대에 있던 n-1개의 원판을 목표 장대로 이동
        hanoi(n - 1, temp, end, start);
    }
}

int main() {
    int N; // 원판의 수
    cin >> N; // 사용자 입력

    // 하노이 탑 문제의 이동 최소 횟수는 2^N - 1
    cout << (1 << N) - 1 << "\n"; // 총 이동 횟수를 출력
    hanoi(N, 1, 3, 2); // hanoi 함수 호출로 원판 이동 과정을 시작

    return 0;
}
