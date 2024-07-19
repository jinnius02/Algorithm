#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// DFS 및 백트래킹을 통해 가능한 모든 연산자 조합을 탐색하는 함수
void dfs(const vector<int>& numbers, vector<int>& ops, int index, int current_result, int& max_result, int& min_result) {
    // base case: 모든 숫자를 사용한 경우
    if (index == numbers.size()) {
        // 현재 계산 결과를 최대값과 최소값과 비교하여 갱신
        max_result = max(max_result, current_result);
        min_result = min(min_result, current_result);
        return;
    }

    // 각 연산자에 대해 재귀적으로 호출하여 다음 숫자를 계산
    for (int i = 0; i < 4; ++i) {
        if (ops[i] > 0) { // 사용할 수 있는 연산자가 있는 경우
            ops[i]--; // 연산자 하나 사용
            int next_result = current_result; // 현재 결과를 다음 연산 결과로 초기화
            if (i == 0) {
                next_result += numbers[index]; // 덧셈
            } else if (i == 1) {
                next_result -= numbers[index]; // 뺄셈
            } else if (i == 2) {
                next_result *= numbers[index]; // 곱셈
            } else if (i == 3) { // 나눗셈
                // 문제 조건에 따른 정수 나눗셈 처리
                if (next_result < 0 && numbers[index] > 0) {
                    next_result = -((-next_result) / numbers[index]);
                } else if (next_result > 0 && numbers[index] < 0) {
                    next_result = -(next_result / (-numbers[index]));
                } else {
                    next_result /= numbers[index];
                }
            }

            // 재귀 호출로 다음 인덱스의 숫자를 처리
            dfs(numbers, ops, index + 1, next_result, max_result, min_result);
            ops[i]++; // 백트래킹을 위해 연산자 복구
        }
    }
}

int main() {
    int N;
    cin >> N; // 숫자의 개수 입력
    vector<int> numbers(N);
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i]; // 수열 입력
    }

    vector<int> ops(4); // 덧셈, 뺄셈, 곱셈, 나눗셈 연산자 개수 입력
    for (int i = 0; i < 4; ++i) {
        cin >> ops[i];
    }

    int max_result = INT_MIN; // 결과의 최댓값을 저장할 변수
    int min_result = INT_MAX; // 결과의 최솟값을 저장할 변수

    // DFS 및 백트래킹을 사용하여 가능한 모든 연산자 조합을 탐색
    dfs(numbers, ops, 1, numbers[0], max_result, min_result);

    // 최댓값과 최솟값 출력
    cout << max_result << endl;
    cout << min_result << endl;

    return 0;
}