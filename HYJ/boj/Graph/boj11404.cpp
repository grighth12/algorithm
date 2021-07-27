#include <iostream>
#include <vector>
#define MAX 100000000

using namespace std;

struct edge {
	long long end;
	long long cost;

	edge(long long end, long long cost) {
		this->end = end;
		this->cost = cost;
	}
};

vector<vector<edge>> adjList;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;

	cin >> N >> M;
	vector<vector<long long>> DP(N + 1, vector<long long>(N + 1, MAX));

	adjList = vector<vector<edge>>(N + 1, vector<edge>());

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) DP[i][j] = 0;
		}
	}

	for (int i = 0; i < M; i++) {
		long long a, b, c;

		cin >> a >> b >> c;
		adjList[a].push_back(edge(b, c));
		if(a != b) DP[a][b] = min(DP[a][b], c);
	}


	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				DP[i][j] = min(DP[i][j], DP[i][k] + DP[k][j]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (DP[i][j] == MAX) {
				cout << 0 << " ";
			}
			else {
				cout << DP[i][j] << " ";
			}
		}
		cout << "\n";
	}

	return 0;

}