#include <iostream>
#include <vector>
using namespace std;

// 조합 C(n, k)를 계산하기 위한 동적 프로그래밍 배열 초기화
vector<vector<long long>> initialize_combinations(int max_size) {
    vector<vector<long long>> C(max_size + 1, vector<long long>(max_size + 1, 0));
    for (int i = 0; i <= max_size; ++i) {
        C[i][0] = C[i][i] = 1; // C(n, 0)과 C(n, n)은 1
        for (int j = 1; j < i; ++j) {
            C[i][j] = C[i-1][j-1] + C[i-1][j]; // 이항계수 재귀 관계
        }
    }
    return C;
}

int main() {
    int T;
    cin >> T;
    
    int max_M = 0; // 입력 중 최대 M값을 저장하기 위한 변수
    vector<pair<int, int>> cases(T);

    // 입력받으면서 동시에 최대 M 값을 찾습니다.
    for (int i = 0; i < T; ++i) {
        int N, M;
        cin >> N >> M;
        cases[i] = {N, M};
        if (M > max_M) max_M = M;
    }

    // 최대 M 값을 사용하여 조합 배열을 한 번에 계산
    vector<vector<long long>> combinations = initialize_combinations(max_M);

    // 각 테스트 케이스에 대해 계산된 조합 값을 출력
    for (auto &case_pair : cases) {
        int N = case_pair.first;
        int M = case_pair.second;
        cout << combinations[M][N] << endl; // C(M, N) 출력
    }

    return 0;
}