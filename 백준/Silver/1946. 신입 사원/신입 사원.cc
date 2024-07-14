//신입사원
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T, N;
    cin >> T; // 테스트 케이스의 수

    while (T--) {
        cin >> N;
        vector<pair<int, int>> applicants(N);

        // 각 지원자의 서류 순위와 면접 순위 입력 받기
        for(int i = 0; i < N; i++) {
            cin >> applicants[i].first >> applicants[i].second;    
        }

        // 서류 순위를 오름차순 정렬
        sort(applicants.begin(), applicants.end()); // 서류 순위로 정렬

        int count = 1; // 최소 한 명은 선택 // 최소 한 명은 선발됨 (서류 순위 1위 지원자)
        int minInterviewRank = applicants[0].second;

        // 나머지 지원자들을 검토하여 면접 순위로 선발 가능한 인원 세기
        for(int i = 1; i < N; i++) {
            if(applicants[i].second < minInterviewRank) {
                count++;
                minInterviewRank = applicants[i].second;
            }
        }

        // 각 테스트 케이스마다 결과 출력
        cout << count << endl;
    }

    return 0;
}