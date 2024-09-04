#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int W, N;
    cin >> W >> N;

    vector<pair<int, int>> locations(N);
    for (int i = 0; i < N; i++) {
        cin >> locations[i].first >> locations[i].second;
    }

    int total_distance = 0;
    int current_load = 0;
    int last_position = 0;

    for (const auto& location : locations) {
        int distance = location.first;
        int waste = location.second;

        // 먼저 현재 위치에서 다음 지점까지 이동
        total_distance += (distance - last_position);
        last_position = distance;

        if (current_load + waste > W) { // 쓰레기 용량 초과 시
            // 쓰레기장으로 돌아가서 쓰레기 비우기
            total_distance += last_position; // 현재 위치에서 쓰레기장까지 거리
            current_load = 0; // 쓰레기 비우고

            // 다시 현재 위치로 돌아오기
            total_distance += last_position;
        }

        current_load += waste; // 쓰레기 싣기

        // 쓰레기차 용량이 정확하게 찼다면 쓰레기장으로 돌아가 비우기
        if (current_load == W) {
            total_distance += last_position; // 쓰레기장으로 돌아가기
            current_load = 0; // 쓰레기 비우기
            last_position = 0; // 쓰레기장 위치로 리셋
        }
    }

    // 모든 지점을 처리한 후에 쓰레기장으로 돌아가기
    if (current_load > 0) {
        total_distance += last_position;
    }

    cout << total_distance << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}