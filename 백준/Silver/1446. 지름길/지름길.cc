#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
    int N, D;
    cin >> N >> D;

    vector<tuple<int, int, int>> shortcuts;
    for (int i = 0; i < N; i++) {
        int start, end, length;
        cin >> start >> end >> length;
        if (end <= D && end > start && length < (end - start)) {  // 지름길이 유효하고 실제로 단축하는 경우에만 추가
            shortcuts.push_back(make_tuple(start, end, length));
        }
    }

    // dp 배열: 각 위치까지의 최소 이동 거리를 저장
    vector<int> dp(D + 1, 1e9);  // 충분히 큰 값으로 초기화
    dp[0] = 0;  // 시작점은 거리가 0

    // 동적 프로그래밍을 사용하여 최소 이동 거리 계산
    for (int i = 0; i <= D; i++) {
        if (i > 0) {
            dp[i] = min(dp[i], dp[i - 1] + 1);  // 바로 이전 위치에서 1km 진행
        }
        for (auto& shortcut : shortcuts) {
            int start = get<0>(shortcut);
            int end = get<1>(shortcut);
            int length = get<2>(shortcut);
            if (i == start && i + (end - start) <= D) {
                dp[end] = min(dp[end], dp[start] + length);
            }
        }
    }

    // 결과 출력
    cout << dp[D] << endl;
    return 0;
}