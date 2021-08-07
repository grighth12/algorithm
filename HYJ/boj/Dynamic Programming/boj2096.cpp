#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;

	cin >> N;

	vector<int> m(3, 0);
	vector<vector<int>> dp1(2, vector<int>(3, 0));
	vector<vector<int>> dp2(2, vector<int>(3, 0));

	for (int i= 0; i < 3; i++) {
		dp2[1][i] = 2000000000;
	}

	// 입력을 받는 즉시 바로 dp를 갱신해야될듯.

	for (int i = 0; i < N; i++) {
		// 슬라이딩 윈도우는 입력을 받은 즉시 처리하는것 , 즉 처리하는 범위가 한정적으로 설정
		// 그리고 그 범위의 요소는 바뀌는 것을 의미
		for (int j = 0; j < 3; j++) {
			cin >> m[j];
		}

		// dp 처리
		for (int j = 0; j < 3; j++) {
			for (int mx = -1; mx <= 1; mx++) {
				int tx = j + mx;
				if (tx >= 0 && tx < 3) {
					dp1[1][j] = max(dp1[1][j],dp1[0][tx] + m[j]);
					dp2[1][j] = min(dp2[1][j], dp2[0][tx] + m[j]);
				}
			}
		}

		for (int j = 0; j < 3; j++) {
			dp1[0][j] = dp1[1][j];
			dp2[0][j] = dp2[1][j];
			dp2[1][j] = 2000000000;
		}

	}
	int Max = 0;
	int Min = 2000000000;
	for (int i = 0; i < 3; i++) {
		Max = max(Max, dp1[0][i]);
		Min = min(Min, dp2[0][i]);
	}

	cout << Max << " " << Min << "\n";

	return 0;
	
}