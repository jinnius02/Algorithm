#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int N; // 강의의 수
    cin >> N;
    vector<pair<int, int>> classroom(N); // 각 강의의 시작과 종료 시간을 저장하는 벡터

    for (int i = 0; i < N; ++i) {
        // 사용자로부터 각 강의의 시작 시간과 종료 시간을 입력 받음
        cin >> classroom[i].first >> classroom[i].second;
    }

    // 강의들을 시작 시간 기준으로 정렬
    sort(classroom.begin(), classroom.end());

    // 최소 힙을 사용해 현재 강의실에서 사용 중인 종료 시간 관리
    priority_queue<int, vector<int>, greater<int>> min_heap;

    // 각 강의를 확인하면서 강의실 관리
    for (int i = 0; i < N; ++i) {
        if (!min_heap.empty() && min_heap.top() <= classroom[i].first) {
            // 현재 강의의 시작 시간이 큐의 최소 종료 시간 이후라면 해당 강의실 재사용
            // 즉, 최소 힙의 최상단 요소(가장 빨리 끝나는 강의실의 종료 시간)를 제거
            // 현재 강의의 시작 시간이 종료 시간 이후라면 재사용
            min_heap.pop();
        }
        // 새 강의의 종료 시간을 힙에 추가하여 강의실 추가 또는 기존 강의실 사용을 나타냄
        min_heap.push(classroom[i].second);
    }

    // 필요한 최소 강의실의 수는 힙의 크기와 동일
    // 우선순위 큐(최소 힙)의 크기는 현재 운영 중인 강의실의 수를 나타냄
    cout << min_heap.size() << endl;

    return 0;
}