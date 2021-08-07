#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;

	cin >> N >> M;

	vector<int> m(N + 1, 0);
	vector<int> c(N + 1, 0);
	vector<vector<long long>> dp(N + 1, vector<long long>(10001 , 0)); // j값은 cost 기준으로 만든다.

	for (int i = 1; i <= N; i++) {
		cin >> m[i];
	}
	int costSum = 0;
	for (int i = 1; i <= N; i++) {
		cin >> c[i];
		costSum += c[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= costSum; j++) {
			if (j - c[i] >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - c[i]] + m[i]);
			}

			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			
		}
	}

	long long ans = 0;
	// 최소 비용 확인
	for (int i = 0; i <= costSum; i++) {
		// M 바이트 확보한 최소비용 (cost 합)
		if (dp[N][i] >= M) {
			ans = i;
			break;
		}
	}

	cout << ans << "\n";
	return 0;
}