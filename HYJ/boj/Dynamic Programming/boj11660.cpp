#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int a, b, c, d;
	int N, M;

	cin >> N >> M;
	vector<vector<int>> m(N + 1, vector<int>(N + 1, 0));
	vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> m[i][j];
		}
	}

	// base √ ±‚»≠
	for (int i = 1; i <= N; i++) {
		dp[i][1] = m[i][1];
	}

	// dp
	for (int i = 1; i <= N; i++) {
		for (int j = 2; j <= N; j++) {
			dp[i][j] = dp[i][j - 1] + m[i][j];
		}
	}
	
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c >> d;
		int sum = 0;

		for (int j = a; j <= c; j++) {
			sum += dp[j][d];
		}
		
		if (b != 1) {
			for (int j = a; j <= c; j++) {
				sum -= dp[j][b - 1];
			}
		}
		cout << sum << "\n";
	}

	return 0;

}