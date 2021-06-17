#include <iostream>
#include <vector>
#include <string>

using namespace std;

string dp[70] = { "" };

string add_string(string a, string b) {
	while (a.length() > b.length()) {
		b = "0" + b;
	}

	while (a.length() < b.length()) {
		a = "0" + a;
	}
	int carry = 0;
	string result = "";
	for (int i = a.length() - 1; i >= 0; i--) {
		int x = a[i] - '0';
		int y = b[i] - '0';
		int sum = x + y + carry;
		carry = sum / 10;
		result = to_string(sum % 10) + result;
	}

	if (carry == 1) {
		result = to_string(1) + result;
	}
	return result;
}

string solution(int n) {
	if (dp[n] != "") return dp[n];

	if (n < 2) {
		return "1";
	}
	else if (n == 2) {
		return "2";
	}
	else if (n == 3) {
		return "4";
	}
	else if (n > 3) {
		// dp ÀúÀå 
		dp[n] = add_string(add_string(solution(n - 1), solution(n - 2)), add_string(solution(n - 3), solution(n - 4)));
		return dp[n];
	}

	return "";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin >> T;

	
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		cout << solution(n) << "\n";
	}

	return 0;
}