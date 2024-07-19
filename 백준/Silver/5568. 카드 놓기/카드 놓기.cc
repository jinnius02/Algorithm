#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// 주어진 카드로 가능한 모든 숫자 조합을 생성하는 함수
void findAllNumbers(vector<string>& cards, int k, set<string>& uniqueNumbers) {
    // 선택된 카드를 추적하는 벡터 초기화
    vector<bool> selected(cards.size(), false);
    // 조합을 만들기 위해 끝에서 k개의 원소를 true로 설정
    fill(selected.end() - k, selected.end(), true);
    
    // 가능한 모든 조합에 대해 반복
    do {
        vector<string> currentCombination;
        // 현재 조합에 선택된 카드를 currentCombination에 추가
        for (int i = 0; i < cards.size(); i++) {
            if (selected[i]) {
                currentCombination.push_back(cards[i]);
            }
        }

        // 현재 조합의 모든 가능한 순열 생성
        sort(currentCombination.begin(), currentCombination.end());
        do {
            string num = "";
            // 순열을 통해 만들어진 카드 조합으로 숫자를 생성
            for (auto& card : currentCombination) {
                num += card;
            }
            // 생성된 숫자를 유니크한 숫자 세트에 추가
            uniqueNumbers.insert(num);
        } while (next_permutation(currentCombination.begin(), currentCombination.end()));
    } while (next_permutation(selected.begin(), selected.end()));
}

int main() {
    int n, k;
    cin >> n >> k; // 사용자로부터 카드의 총 수와 조합할 카드 수를 입력받음
    vector<string> cards(n);
    for (int i = 0; i < n; i++) {
        cin >> cards[i]; // 카드에 적힌 숫자를 입력받음
    }

    set<string> uniqueNumbers; // 중복없이 모든 숫자 조합을 저장할 세트
    findAllNumbers(cards, k, uniqueNumbers); // 모든 유니크한 숫자 조합을 생성

    cout << uniqueNumbers.size() << endl; // 생성된 유니크한 숫자 조합의 수를 출력
    return 0;
}