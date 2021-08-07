#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string str1;
	string str2;

	cin >> str1 >> str2;

	int N = str1.length();
	int M = str2.length();

	vector<vector<int>> dp = vector<vector<int>>(N + 1, vector<int>(M + 1));

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}

			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans;

	return 0;
}