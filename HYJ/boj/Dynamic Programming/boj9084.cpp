#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n;
		int M;
		cin >> n;
		vector<int> nums(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> nums[i];
		}
		cin >> M;
		vector<int> dp(M + 1, 0);

		dp[0] = 1;

		for (int i = 0; i < n; i++) {
			for (int j = nums[i]; j <= M; j++) {
				dp[j] = dp[j - nums[i]] + dp[j];
			}
		}

		cout << dp[M] << "\n";
	}

	return 0;
}