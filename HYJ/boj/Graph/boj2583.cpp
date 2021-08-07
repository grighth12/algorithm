#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<bool>> check;
vector<vector<int>> m;
vector<int> sums;


int N, M, K;
bool isPossible(int y, int x) {
	return 0 <= y && y < N && 0 <= x && x < M;
}

int DFS(int y, int x) {
	// Ã¼Å©ÀÎ
	check[y][x] = true;
	
	int mx[4] = { 0,0, 1, -1 };
	int my[4] = { 1,-1, 0, 0 };

	int sum = 0;
	for (int i = 0; i < 4; i++) {
		int tx = mx[i] + x;
		int ty = my[i] + y;

		if (isPossible(ty, tx) && !check[ty][tx]) {
			sum += DFS(ty, tx) + 1;
		}
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;

	check = vector<vector<bool>>(N, vector<bool>(M, false));
	m = vector<vector<int>>(N, vector<int>(M, 1));

	for (int k = 0; k< K; k++) {
		int x1, y1, x2, y2;

		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++) {
				m[i][j] = 0;
				check[i][j] = true;
			}
		}

	}

	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!check[i][j]) {
				count++;
				int sum = DFS(i, j) + 1;
				sums.push_back(sum);
			}
		}
	}

	sort(sums.begin(), sums.end());

	cout << count << "\n";
	for (int i = 0; i < sums.size(); i++) {
		cout << sums[i] << " ";
	}

	return 0;
}