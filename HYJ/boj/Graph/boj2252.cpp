#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct edge {
	int start;
	int end;

	edge(int start, int end) {
		this->start = start;
		this->end = end;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;

	cin >> N >> M;

	vector<int> indegree(N + 1, 0);
	vector<vector<edge>> edges(N + 1, vector<edge>());

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(edge(a, b));
		indegree[b]++;
	}

	queue<int> q;

	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		cout << now << " ";

		int size = edges[now].size();
		for (int i = 0; i < size; i++) {
			int target = edges[now][i].end;
			indegree[target]--;
			if (indegree[target] == 0) {
				q.push(target);
			}
		}
	}
	return 0;

}