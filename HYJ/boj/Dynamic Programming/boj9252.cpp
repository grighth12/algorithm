#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	string str1, str2;

	cin >> str1 >> str2;
	int N = str1.length();
	int M = str2.length();

	vector<vector<int>> dp(N + 1, vector<int>(M +1, 0));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++) {
			dp[i][j] = dp[i - 1][j];
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i-1][j]);
			}
		}
	}

	cout << dp[N][M] << "\n";
	int n = N;
	int m = M;
	stack<char> s;
	while (n != 0 && m != 0) {
		// n과 m을 지칭하는 문자열의 문자들이 같은가??
		if (str1[n-1] == str2[m-1]) {
			s.push(str1[n-1]);
			n--;
			m--;
		}
		else if (dp[n - 1][m] == dp[n][m]) {
			n--;
		}
		else if (dp[n][m - 1] == dp[n][m]) {
			m--;
		}
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	cout << "\n";

	return 0;
}