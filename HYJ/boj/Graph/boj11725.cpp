#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> m;
vector<int> check;

void DFS(int now, int parent) {
	// 체크인
	// 목적지인가?
	if (check[now] == 0) {
		check[now] = parent;
	}
	else {
		return;
	}
	// 순회할 수 있는가?
	int len = m[now].size();
	for (int i = 0; i < len; i++) {
		// 방문할 수 있는가?
		if (check[m[now][i]] == 0) {
			// 방문
			DFS(m[now][i], now);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	m = vector<vector<int>>(N + 1);
	check = vector<int>(N + 1, 0);
	for (int i = 0; i < N-1; i++) {
		int a, b;
		cin >> a >> b;

		m[a].push_back(b);
		m[b].push_back(a);
	}

	DFS(1, -1);

	for (int i = 2; i <= N; i++) {
		cout << check[i] << "\n";
	}
	return 0;
}