#include <iostream>
#include <vector>

using namespace std;

int s, e;

vector<vector<int>> m;
vector<bool> check;

int ans = -1;
bool isFound = false;

void DFS(int start, int count) {
	if (isFound) return;
	// 체크인
	check[start] = true;
	// 목적지인가?
	if (start == e) {
		ans = count;
		isFound = true;
		return;
	}

	int len = m[start].size();

	// 방문할 수 있는가?
	for (int i = 0; i < len; i++) {
		// 진짜 들어갈 수 있는가
		if (!check[m[start][i]]) {
			//cout << m[start][i] << "\n";
			// 방문
			DFS(m[start][i], count + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	m = vector<vector<int>>(N + 1);
	check = vector<bool>(N + 1, false);
	cin >> s >> e;
	
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		m[x].push_back(y);
		m[y].push_back(x);

	}

	DFS(s, 0);

	if (isFound) {
		cout << ans << "\n";
	}
	else {
		cout << -1 << "\n";
	}
	return 0;
}