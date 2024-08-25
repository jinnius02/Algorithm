#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string expression;
    cin >> expression;

    vector<int> numbers;   // 숫자들을 저장할 벡터
    vector<char> ops;      // 연산자들을 저장할 벡터
    int temp = 0;

    // 첫 번째 숫자를 읽어들이는 부분
    for (char ch : expression) {
        if (isdigit(ch)) {
            temp = temp * 10 + (ch - '0'); // 문자를 숫자로 변환하여 temp에 추가
        } else {
            numbers.push_back(temp); // 저장된 숫자를 벡터에 추가
            ops.push_back(ch);       // 연산자를 벡터에 추가
            temp = 0;                // temp 초기화
        }
    }
    numbers.push_back(temp); // 마지막 숫자 추가

    int result = numbers[0];  // 결과 초기값은 첫 번째 숫자로 설정

    // '-' 연산자가 나타나면 그 이후의 모든 숫자를 빼야 하므로, 그 전까지는 더한다
    bool minusFound = false;  // '-' 연산자 발견 여부
    for (size_t i = 0; i < ops.size(); ++i) {
        if (ops[i] == '+' && !minusFound) {
            // '-' 연산자 전까지는 모두 더한다
            result += numbers[i + 1];
        } else {
            // 첫 '-' 이후는 모든 숫자를 빼야 한다
            minusFound = true;
            result -= numbers[i + 1];
        }
    }

    cout << result << endl; // 계산된 결과 출력

    return 0;
}