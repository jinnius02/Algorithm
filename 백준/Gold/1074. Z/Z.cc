#include <iostream>
using namespace std;

int findZ(int N, int r, int c) {
    if (N == 0) return 0; // 기저 조건: 가장 작은 단위의 크기에 도달했을 때
    
    int half = 1 << (N - 1); // 배열을 2^(N-1) × 2^(N-1)으로 나눈다.
    int count = half * half; // 각 사분면이 가질 수 있는 원소의 수
    
    if (r < half && c < half) {
        // 1사분면 (왼쪽 상단)
        return findZ(N - 1, r, c);
    } else if (r < half && c >= half) {
        // 2사분면 (오른쪽 상단)
        return count + findZ(N - 1, r, c - half);
    } else if (r >= half && c < half) {
        // 3사분면 (왼쪽 하단)
        return 2 * count + findZ(N - 1, r - half, c);
    } else {
        // 4사분면 (오른쪽 하단)
        return 3 * count + findZ(N - 1, r - half, c - half);
    }
}

int main() {
    int N, r, c;
    cin >> N >> r >> c;
    cout << findZ(N, r, c) << endl;
    return 0;
}