#include <iostream>
using namespace std;

// 해당 함수는 각 n에 대해 1, 2, 3의 합으로 나타내는 방법의 수를 계산하여 저장합니다.
void precompute(int ways[], int max_n) {
    // 기본 경우 초기화
    ways[0] = 1; // 0을 나타내는 방법은 아무것도 선택하지 않는 하나의 방법 뿐이다.
    for (int i = 1; i <= max_n; i++) {
        // i를 만들 수 있는 경우의 수를 계산
        if (i >= 1) ways[i] += ways[i-1]; // 1을 추가하는 경우
        if (i >= 2) ways[i] += ways[i-2]; // 2를 추가하는 경우
        if (i >= 3) ways[i] += ways[i-3]; // 3을 추가하는 경우
    }
}

int main() {
    int T, n;
    cin >> T; // 테스트 케이스의 개수 입력 받음

    // n이 최대 10이므로, ways 배열을 11 크기로 선언
    int ways[11] = {0};
    precompute(ways, 10); // 미리 계산 실행

    while (T--) {
        cin >> n; // 각 테스트 케이스에 대한 n 입력
        cout << ways[n] << endl; // 미리 계산된 결과 출력
    }

    return 0;
}
