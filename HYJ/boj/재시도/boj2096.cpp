#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;

	cin >> N;

	vector<vector<int>> m(N, vector<int>(3, 0));
	vector<vector<int>> dp1(N, vector<int>(3, 0));
	vector<vector<int>> dp2(N, vector<int>(3, 2000000000));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> m[i][j];
		}
	}
	// base
	dp1[0][0] = m[0][0];
	dp1[0][1] = m[0][1];
	dp1[0][2] = m[0][2];

	dp2[0][0] = m[0][0];
	dp2[0][1] = m[0][1];
	dp2[0][2] = m[0][2];
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			for (int mx = -1; mx <= 1; mx++) {
				int tx = j + mx;
				if (tx >= 0 && tx < N) {
					dp1[i][j] = max(dp1[i][j], dp1[i - 1][tx] + m[i][j]);
					dp2[i][j] = min(dp2[i][j], dp2[i - 1][tx] + m[i][j]);
				}
			}
		}
	}
	int Max = 0;
	int Min = 2000000000;

	for (int i = 0; i < 3; i++) {
		Min = min(Min, dp2[N-1][i]);
		Max = max(Max, dp1[N-1][i]);
	}

	cout << Max << " " << Min << "\n";

	return 0;
}