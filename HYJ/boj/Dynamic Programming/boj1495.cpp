#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// 메모리 초과 (큐를 사용해서 풀려고 했었음)
void version1(int N, int S, int M) {
	vector<short> nums(N, 0);
	queue<short> dp;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	dp.push(S);
	int m = 0;
	bool isSomething =false;
	for (int i = 0; i < N; i++) {
		int length = dp.size();
		isSomething = false;
		m = 0;
		int j = 0;
		while (j < length) {
			short a = dp.front();
			dp.pop();
			if (a + nums[i] <= M) {
				isSomething = true;
				dp.push(a + nums[i]);
				m = max(m, a + nums[i]);
			}

			if (a - nums[i] >= 0) {
				isSomething = true;
				dp.push(a - nums[i]);
				m = max(m, a - nums[i]);
			}
			j++;
		}
	}

	if (isSomething) {
		cout << m;
	}
	else {
		cout << "-1";
	}
}

void version2() {
	/*
	vector<int> dp(M + 1, 0);
	vector<int> nums(N, 0);
	// -1로 초기화
	for (int i = 0; i <= M; i++) {
		dp[i] = -1;
	}

	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	dp[S] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= M; j++) {
			if (dp[j] == i) {
				if (j + nums[i] <= M) {
					dp[j + nums[i]] = i + 1;
				}
				if (j - nums[i] >= 0) {
					dp[j - nums[i]] = i + 1;
				}
			}
		}
	}



	for (int i = 0; i <= M; i++) {
		cout << dp[i] << " ";
	}
	cout << "\n";

	int m = -1;
	for (int i = 0; i <= M; i++) {
		if (dp[i] == N) m = max(m, i);
	}

	cout << m;

	*/
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, S, M;
	cin >> N >> S >> M;

	vector<vector<bool>> dp(N + 1, vector<bool>(M + 1, false));
	vector<int> nums(N + 1, 0);

	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	dp[0][S] = true;

	for (int i = 0; i < N ; i++) {
		for (int j = 0; j <= M; j++) {
			if (dp[i][j]) {
				if(j - nums[i] >= 0) dp[i + 1][j - nums[i]] = true;
				if(j+ nums[i] <= M) dp[i + 1][j + nums[i]] = true;
			}
		}
	}
	
	/*
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
	*/
	int m = -1;
	for (int i = 0; i <= M; i++) {
		if (dp[N][i])m = max(m, i);
	}

	cout << m;
	
	return 0;
}