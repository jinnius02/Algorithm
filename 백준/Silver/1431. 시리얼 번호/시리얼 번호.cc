#include <iostream>
#include <vector>
#include <algorithm> // sort 사용
#include <string> // string 사용
using namespace std;

// 시리얼 번호의 숫자들의 합을 구하는 함수
int sumOfDigits(const string &s) {
    int sum = 0;
    for (char c : s) {
        if (isdigit(c)) { // 숫자인 경우에만 더함
            sum += c - '0'; // 문자를 숫자로 변환하여 더함
        }
    }
    return sum;
}

// 정렬 조건을 설정하는 함수
bool compare(const string &a, const string &b) {
    // 길이가 짧은 순서
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    // 길이가 같다면 숫자의 합을 비교
    int sumA = sumOfDigits(a);
    int sumB = sumOfDigits(b);
    if (sumA != sumB) {
        return sumA < sumB;
    }
    // 숫자의 합도 같다면 사전순으로 비교
    return a < b;
}

int main() {
    int N;
    cin >> N;
    vector<string> serials(N); // 시리얼 번호를 저장할 벡터

    // 시리얼 번호 입력 받기
    for (int i = 0; i < N; ++i) {
        cin >> serials[i];
    }

    // 정의된 비교 함수를 사용하여 벡터 정렬
    sort(serials.begin(), serials.end(), compare);

    // 정렬된 시리얼 번호 출력
    for (const string &serial : serials) {
        cout << serial << '\n';
    }

    return 0;
}
