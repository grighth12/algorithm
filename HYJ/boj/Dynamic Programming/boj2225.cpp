#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));

	for (int i = 0; i <= K; i++) {
		dp[i][0] = 1;
	}

	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) %1000000000;
		}
	}

	/*
	for (int i = 0; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	*/
	cout << dp[K][N];
	
	return 0;

}