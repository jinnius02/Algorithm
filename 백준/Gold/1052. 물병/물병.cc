#include <iostream>

using namespace std;

// 물병을 K개 이하로 만들기 위해 필요한 최소 물병 구매 수를 계산하는 함수
int minBottles(int N, int K) {
    int additionalBottles = 0;  // 추가로 필요한 물병의 수

    while (true) {
        int currentBottles = N;  // 현재의 물병 수
        int bottleCount = 0;     // 합쳐진 후 남는 물병의 수

        // 현재 물병의 개수를 이진수로 변환하여 1의 개수를 세어 계산한다
        while (currentBottles > 0) {
            if (currentBottles & 1) ++bottleCount;
            currentBottles >>= 1;
        }

        // 만약 물병의 수가 K 이하면 루프를 종료
        if (bottleCount <= K) break;

        // K보다 많으면 물병 하나를 추가하고 다시 계산
        ++additionalBottles;
        ++N;
    }

    return additionalBottles;
}

int main() {
    int N, K;
    cin >> N >> K;

    cout << minBottles(N, K) << endl;

    return 0;
}