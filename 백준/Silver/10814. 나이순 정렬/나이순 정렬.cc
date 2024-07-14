// 나이순 정렬
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<pair<int, string>> members(N);

    for (int i = 0; i < N; i++) {
        cin >> members[i].first >> members[i].second;
    }
    
    // 우선적으로 나이 오름차순 정렬 -> 나이가 같을 경우) 가입한 순으로 정렬 => Stable Sort
    stable_sort(members.begin(), members.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
    return a.first < b.first; // 나이에 따라 오름차순 정렬
});
    // members 벡터를 정렬하기 위해 stable_sort 함수 사용. 사용된 람다 표현식은 두 회원 비교 -> 나이가 적은 회원이 앞에 오도록 정렬.

	// stable_sort: 벡터를 정렬하면서 원래의 순서(가입 순서)를 나이가 같을 때 유지합니다.
    // 람다 표현식 [](const pair<int, string>& a, const pair<int, string>& b): 두 회원의 나이 비교.
	// return a.first < b.first;: a 회원의 나이가 b 회원보다 작으면 true -> 반환 a를 b보다 앞에 위치시킴.

    // 나이 오름차순 -> 결과 출력
    for (int i = 0; i < N; i++) {
        cout << members[i].first << " " << members[i].second << "\n";
    }

    return 0;
}