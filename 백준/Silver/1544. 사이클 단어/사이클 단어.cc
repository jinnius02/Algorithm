#include <iostream>
#include <set>
#include <string>
using namespace std;

// 주어진 문자열을 모든 가능한 사이클 형태로 변환하여 결과 집합을 반환하는 함수
set<string> generateCycles(const string& word) {
    set<string> cycles;
    int len = word.length();
    for (int i = 0; i < len; i++) {
        // 문자열을 왼쪽으로 회전시켜 새로운 사이클을 생성
        string cycle = word.substr(i) + word.substr(0, i);
        cycles.insert(cycle);
    }
    return cycles;
}

int main() {
    int N;
    cin >> N;
    
    set<string> uniqueWords;
    while (N--) {
        string word;
        cin >> word;
        
        // 입력받은 단어에 대한 모든 사이클을 생성
        set<string> cycles = generateCycles(word);
        bool isNewWord = true;
        
        // 이미 존재하는 사이클과 비교
        for (const string& unique : uniqueWords) {
            if (cycles.find(unique) != cycles.end()) {
                isNewWord = false;
                break;
            }
        }
        
        // 새로운 사이클 단어를 찾은 경우, 그 단어의 첫 번째 사이클만 저장
        if (isNewWord) {
            uniqueWords.insert(*cycles.begin());
        }
    }
    
    // 서로 다른 사이클 단어의 수 출력
    cout << uniqueWords.size() << endl;
    return 0;
}