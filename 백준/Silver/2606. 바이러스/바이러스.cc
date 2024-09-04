#include <iostream>
#include <vector>
#include <cstring> // memset을 사용하기 위해 포함

using namespace std;

// 네트워크 연결을 저장할 인접 리스트
vector<int> network[101];
// 방문 여부를 표시할 배열
bool visited[101];
// 웜 바이러스에 감염된 컴퓨터의 수
int infected_count = 0;

// DFS 함수 정의
void dfs(int computer) {
    // 현재 컴퓨터를 방문 처리
    visited[computer] = true;
    // 감염된 컴퓨터 수 증가
    infected_count++;
    
    // 현재 컴퓨터와 연결된 모든 컴퓨터에 대해 탐색
    for (int i = 0; i < network[computer].size(); i++) {
        int next = network[computer][i];
        // 아직 방문하지 않았다면 재귀적으로 탐색
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    int N, pairs;
    cin >> N >> pairs;

    // 연결 정보 입력 받기
    for (int i = 0; i < pairs; i++) {
        int a, b;
        cin >> a >> b;
        network[a].push_back(b);
        network[b].push_back(a);
    }

    // 방문 배열 초기화
    memset(visited, false, sizeof(visited));

    // 1번 컴퓨터부터 DFS 시작
    dfs(1);

    // 1번 컴퓨터 자신을 제외한 감염된 컴퓨터 수 출력
    cout << infected_count - 1 << endl;

    return 0;
}
