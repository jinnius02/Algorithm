#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, a, b, m;
vector<vector<int>> adj; // 인접 리스트

int findKinship(int start, int target) {
    vector<int> dist(n+1, -1); // 각 노드까지의 거리 초기화
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int next : adj[current]) {
            if (dist[next] == -1) { // 방문하지 않았다면
                dist[next] = dist[current] + 1;
                q.push(next);
                if (next == target) {
                    return dist[next]; // 타겟을 찾으면 거리 반환
                }
            }
        }
    }
    
    return -1; // 연결되지 않았을 경우
}

int main() {
    cin >> n >> a >> b >> m;
    adj.resize(n+1);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y); // x는 y의 부모
        adj[y].push_back(x); // y는 x의 자식, 양방향으로 추가
    }

    cout << findKinship(a, b) << endl;

    return 0;
}