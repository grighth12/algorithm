#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int dp[21][21][21] = { 0 };

	for (int i = 0; i <= 20; i++) {
		for (int j = 0; j <= 20; j++) {
			for (int k = 0; k <= 20; k++) {
				dp[i][j][k] = 1;
			}
		}
	}

	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= 20; j++) {
			for (int k = 1; k <= 20; k++) {
				if (i == 0 || j == 0 || k == 0) dp[i][j][k] = 1;
				else if (i < j && j < k) {
					dp[i][j][k] = dp[i][j][k - 1] + dp[i][j - 1][k - 1] - dp[i][j - 1][k];
				}
				else {
					dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] - dp[i - 1][j - 1][k - 1];
				}
			}
		}
	}
	
	bool isWorking = true;

	while (isWorking) {
		
		int a, b, c;
		int sol = 0;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) {
			break;
		}
		
		if (a <= 0 || b <= 0 || c <= 0)sol = 1;
		else if (a > 20 || b > 20 || c > 20) sol = dp[20][20][20];
		else sol = dp[a][b][c];


		printf("w(%d, %d, %d) = %d\n", a, b, c, sol);
	}
	
	return 0;
}