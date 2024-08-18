#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++의 iostream과 C의 stdio의 동기화를 끊어 입출력 성능을 향상시킴
    cin.tie(NULL); // cin과 cout의 묶음을 해제하여 입출력 속도를 향상시킴

    int T; // 테스트 케이스의 개수
    cin >> T;

    while (T--) {
        int N; // 수첩 1에 적힌 정수의 개수
        cin >> N;

        unordered_set<int> notebook1; // 수첩 1에 적힌 정수들을 저장할 집합

        // 수첩 1의 정수들을 집합에 저장
        for (int i = 0; i < N; ++i) {
            int num;
            cin >> num;
            notebook1.insert(num);
        }

        int M; // 수첩 2에 적힌 정수의 개수
        cin >> M;

        // 수첩 2의 정수들을 하나씩 검사하여 수첩 1에 있는지 확인
        for (int i = 0; i < M; ++i) {
            int query;
            cin >> query;
            if (notebook1.find(query) != notebook1.end()) {
                cout << "1\n"; // 수첩 1에 있으면 1 출력
            } else {
                cout << "0\n"; // 수첩 1에 없으면 0 출력
            }
        }
    }

    return 0;
}