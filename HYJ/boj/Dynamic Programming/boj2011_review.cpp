#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a;
	bool isAnswer = true;

	cin >> a;

	int n = a.length();

	vector<int> dp(n + 1, 0);
	vector<int> s(n + 1, 0);

	s[0] = 0;
	for (int i = 0; i < n; i++) {
		s[i + 1] = a[i] - '0';
	}
	
	dp[0] = 1;

	for (int i = 1; i <= n; i++) {
		// 한문자를 생각했을 때 현재 자리가 0이 아니라면, 예전 경우랑 똑같다.
		if (s[i] != 0) {
			dp[i] = dp[i - 1] % 1000000;
		}

		// 앞문자를 포함해서 숫자를 만들었을 때
		int x = s[i] + s[i - 1] * 10;

		// 10~26사이라면  dp[i-2] + dp[i]을 해준다.
		if (10 <= x && x <= 26) {
			dp[i] = (dp[i] + dp[i - 2]) % 1000000;
		}
	}

	cout << dp[n] % 1000000;


	return 0;

}