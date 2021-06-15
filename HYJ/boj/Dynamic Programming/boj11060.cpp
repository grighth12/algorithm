#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> nums(n + 1, 0);
	vector<int> dp(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}

	for (int i = 0; i <= n; i++) {
		dp[i] = 2000000000;
	}

	dp[1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= i + nums[i] && j <= n; j++) {
			dp[j] = min(dp[j], dp[i] + 1);
		}
	}

	/*

	for (int i = 1; i <= n; i++) {
		cout << dp[i] << " ";
	}
	*/
	if (dp[n] >= 2000000000) {
		cout << -1;
	}
	else {
		cout << dp[n];
	}

	return 0;
}
