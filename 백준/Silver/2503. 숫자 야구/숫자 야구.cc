#include <iostream>
#include <vector>

using namespace std;

// 민혁이의 질문에 대한 영수의 응답을 확인하는 함수
bool matches(string guess, string candidate, int targetStrikes, int targetBalls) {
    int strikes = 0, balls = 0;
    for (int i = 0; i < 3; ++i) {
        if (guess[i] == candidate[i])
            strikes++;
        for (int j = 0; j < 3; ++j) {
            if (i != j && guess[i] == candidate[j])
                balls++;
        }
    }
    return strikes == targetStrikes && balls == targetBalls;
}

int main() {
    int N;
    cin >> N;

    vector<string> questions(N);
    vector<int> strikes(N), balls(N);
    for (int i = 0; i < N; ++i) {
        cin >> questions[i] >> strikes[i] >> balls[i];
    }

    int count = 0;
    // 모든 가능한 세 자리 수를 순회
    for (int num = 123; num <= 987; ++num) {
        string candidate = to_string(num);
        // 중복된 숫자 또는 0 포함 숫자 거르기
        if (candidate[0] == candidate[1] || candidate[1] == candidate[2] || candidate[0] == candidate[2] || candidate.find('0') != string::npos)
            continue;

        bool possible = true;
        // 모든 질문과 응답과 비교
        for (int i = 0; i < N && possible; ++i) {
            if (!matches(questions[i], candidate, strikes[i], balls[i])) {
                possible = false;
            }
        }

        if (possible) count++;
    }

    cout << count << endl;
    return 0;
}