#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;

	cin >> N >> M;
	vector<long long> v(N, 0);
	vector<long long> dp(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	dp[0] = v[0];

	for (int i = 1; i < N; i++) {
		dp[i] = dp[i - 1] + v[i];
	}


	for (int i = 0; i < M; i++) {
		long long a, b;
		cin >> a >> b;
		if (a == 1) cout << dp[b - 1] << "\n";
		else {
			cout << dp[b - 1] - dp[a - 2] << "\n";
		}
		
	}

	return 0;
}