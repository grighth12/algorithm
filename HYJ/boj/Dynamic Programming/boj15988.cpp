#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, t;
	cin >> t;
	vector<int> nums(t, 0);
	int m = 3;
	for (int i = 0; i < t; i++) {
		cin >> n;
		m = max(m, n);
		nums[i] = n;
	}
	

	vector<int> dp(m + 1, 0);

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= m; i++) {
		dp[i] = ((dp[i - 1] + dp[i - 2]) % 1000000009 + dp[i - 3]) % 1000000009;
	}
	
	for (int i = 0; i < t; i++) {
		cout << dp[nums[i]]<< "\n";
	}

	return 0;
}
