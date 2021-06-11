#include <iostream>
#include <string>
#include <vector>

using namespace std;

string add_string(string a, string b) {
	// 자리수 맞추기
	while (a.length() > b.length()) {
		b = '0' + b;
	}

	while (a.length() < b.length()) {
		a = '0' + a;
	}

	string answer = "";
	int n = a.length();
	int carry = 0;
	for (int i = n - 1; i >= 0; i--) {
		int num1 = a[i] - '0';
		int num2 = b[i] - '0';
		int sum = num1 + num2 + carry;
		carry = sum / 10;
		int digit = sum % 10;
		char ch = digit + '0';
		answer = ch + answer;
	}

	if (carry == 1) {
		answer = '1' + answer;
	}

	return answer;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;

	cin >> n >> m;
	
	string dp[101][101];

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m && i >= j; j++) {
			if (i == j || j == 0) dp[i][j] = "1";
			else {
				dp[i][j] = add_string(dp[i - 1][j - 1], dp[i - 1][j]);
			}
			
		}
	}
	/*
	vector<vector<string>> dp;
	
	for (int i = 0; i <= n; i++) {
		vector<string> strings;
		for (int j = 0; j <= m; j++) {
			if (i == j || (j == 0)) strings.push_back("1");
			else strings.push_back("0");
		}
		dp.push_back(strings);
	}

	
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == j || (j == 0)) dp[i][j] = "1";
			else dp[i][j] = add_string(dp[i - 1][j - 1], dp[i - 1][j]);
		}
	}
	*/



	cout << dp[n][m];
	
	return 0;
}