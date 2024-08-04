#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int N;
vector <int> v[3010];
int res[3010];

bool visited[3010] = { false, };

bool cur_road[3010] = { false, };
bool flag_cur = false;

void dfs(int start, int num , int line) {

	visited[num] = true;
	cur_road[num] = true;

	int su;
	for (int i = 0; i < v[num].size(); i++) {
		su = v[num][i];
		if (su == start && line >= 2) {
			flag_cur = true;
			return;
		}

		if (visited[su]) continue;
		dfs(start, su, line + 1);

		if (flag_cur) return;
	}

	visited[num] = false;
	if(!flag_cur) cur_road[num] = false;
}


void find_rec() {
	for (int i = 1; i <= N; i++) {
		if (!flag_cur) dfs(i, i, 0);
		else return;
	}

}

void bfs(int num) {
	queue<int>q;
	bool visited[3010] = { false, };

	q.push(num);
	visited[num] = true;

	int su, nsu;
	int line = 0;

	while (!q.empty()) {
		int size = q.size();

		line++;
		for (int s = 0; s < size; s++) {
			su = q.front();
			q.pop();
			if (cur_road[su]) {
				res[num] = --line;
				return;
			}
			for (int i = 0; i < v[su].size(); i++) {
				nsu = v[su][i];
				if (visited[nsu]) continue;
				q.push(nsu);
				visited[nsu] = true;
			}
		}
	}
}

void get_res() {

	for (int i = 1; i <= N; i++) {
		if (!cur_road[i]) bfs(i);
		else res[i] = 0;
	}
}

void Solve() {
	find_rec();//순환 찾기 dfs
	get_res();//각노드마다 최소거리 구하기 bfs

	for (int i = 1; i <= N; i++)
		cout << res[i] << " ";

	cout << endl;

}

int main()
{
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < 3010; i++)
		sort(v[i].begin(), v[i].end());

	Solve();
	return 0;
}