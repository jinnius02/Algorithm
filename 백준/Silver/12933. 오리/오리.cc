#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int minDucks(string sound) {
    // 각 오리의 현재 위치를 저장하는 배열
    vector<int> ducks(2500, -1);
    // 총 오리 수 카운트
    int numDucks = 0;
    
    for (char c : sound) {
        if (c == 'q') {
            // 'q'가 발견되면 새로운 오리의 시작을 찾거나, 다시 'q'를 시작하는 오리를 찾음
            bool found = false;
            for (int i = 0; i < numDucks; i++) {
                if (ducks[i] == -1) {
                    ducks[i] = 0;  // 새로 'q'를 시작함
                    found = true;
                    break;
                }
            }
            if (!found) {
                if (numDucks < 2500) {
                    ducks[numDucks++] = 0;
                }
            }
        } else {
            // 'q' 이외의 문자는 기존 오리들 중에 적절한 위치를 찾아서 진행
            char expected[] = {'u', 'a', 'c', 'k'};
            int idx = (c == 'u') ? 1 : (c == 'a') ? 2 : (c == 'c') ? 3 : 4;
            bool found = false;
            for (int i = 0; i < numDucks; i++) {
                if (ducks[i] == idx - 1) {
                    ducks[i] = idx; // 다음 문자로 진행
                    if (c == 'k') {
                        ducks[i] = -1; // 'k'가 끝나면 오리 울음소리 완성
                    }
                    found = true;
                    break;
                }
            }
            if (!found) return -1; // 올바른 순서가 아님
        }
    }
    
    // 모든 오리가 'quack'을 완성했는지 확인
    for (int i = 0; i < numDucks; i++) {
        if (ducks[i] != -1) return -1; // 완성되지 않은 오리가 있음
    }
    
    return numDucks; // 최소 오리 수 반환
}

int main() {
    string sound;
    cin >> sound;
    int result = minDucks(sound);
    cout << result << endl;
    return 0;
}