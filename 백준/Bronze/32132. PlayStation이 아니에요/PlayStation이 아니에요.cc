#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 주어진 문자열 s에서 모든 숫자를 제거한 버전을 반환하는 함수
string removeDigits(string s) {
    s.erase(remove_if(s.begin(), s.end(), ::isdigit), s.end());
    return s;
}

int main() {
    int N;
    cin >> N;
    
    string s;
    cin >> s;

    // 숫자 '0'부터 '9'까지 차례대로 제거를 시도하면서 "PS4"와 "PS5"를 찾지 못하도록 한다.
    string result = s; // 가장 긴 결과를 저장할 변수, 초기값은 원본 문자열
    bool found = true; // "PS4" 또는 "PS5"가 발견되었는지 여부를 나타내는 플래그

    // "PS4" 또는 "PS5"가 없을 때까지 숫자를 제거
    while (found) {
        found = false; // 플래그 초기화
        // "PS4"와 "PS5"를 순차적으로 검사
        for (string target : {"PS4", "PS5"}) {
            size_t pos = result.find(target); // 현재 결과에서 target 문자열 위치 찾기
            if (pos != string::npos) { // target이 발견된 경우
                found = true; // 발견 플래그 설정
                // 발견된 target 주변의 숫자를 제거
                string newResult;
                for (char &c : result) {
                    if (isdigit(c) && (pos <= &c - &result[0] && &c - &result[0] < pos + target.length())) {
                        // 숫자가 target의 위치에 있다면 제거
                        continue;
                    }
                    newResult += c; // 그 외 문자는 새 문자열에 추가
                }
                result = newResult; // 결과 업데이트
                break; // 더 이상 다른 target을 검사할 필요가 없으므로 반복 중단
            }
        }
    }

    // 결과 출력
    cout << result << endl;
    return 0;
}