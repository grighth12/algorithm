#include <iostream>
#include <vector>

#define MAX 100000000
using namespace std;

vector<vector<int>> dist;

int main() {
	int N, M;

	cin >> N >> M;

	dist = vector<vector<int>>(N + 1, vector<int>(N + 1, MAX));

	for (int i = 1; i <= N; i++) {
		dist[i][i] = 0;
	}

	for (int i = 0; i < M; i++) {
		int a, b;

		cin >> a >> b;

		dist[a][b] = 1;
		dist[b][a] = 1;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int mi = MAX;
	int index = N;
	for (int i = N; i >= 0; i--){
		int sum = 0;
		for (int j = 1; j <= N; j++) {
			sum += dist[i][j];
		}
		if (mi >= sum) {
			mi = sum;
			index = i;
		}
	}

	cout << index << "\n";

	return 0;
}