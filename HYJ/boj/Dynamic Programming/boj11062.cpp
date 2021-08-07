#include <iostream>
#include <vector>

using namespace std;

vector<int> datas;
vector<vector<vector<int>>> dp;

// DP 풀떄 팁 !!! : DP를 잘 정의하자'
// DP는 분할정복으로 풀 수가 있다. 분할 정복으로 생각하는 연습을 해보자.
// DP[flag][start][end] : flag 차례, start ~end 사이에서 근우가 얻을 최대의 점수 

int Game(int start, int end, int flag) {

	// 같으면 종료
	if (start == end) {
		// 근우일 떄
		if (flag == 0) {
			return dp[flag][start][end] = datas[start];
		}
		else {
			// 명우일 떄
			return dp[flag][start][end] = 0;
		}
	}

	//구했는가?
	if (dp[flag][start][end] != 0) return  dp[flag][start][end];


	// 게임 진행
	if (flag == 0) {
		// 근우 일때
		return dp[flag][start][end] = max(Game(start + 1, end, 1) + datas[start]
			, Game(start, end - 1, 1) + datas[end]);
	}
	else {
		// 명우 일때는 dp의 정의가 (근우, 명우 차례일 때)근우의 점수이므로 
		// 근우의 점수가 최소값으로 만드는 점수를 만들어야된다.
		return dp[flag][start][end] = min(Game(start + 1, end, 0),
			Game(start, end - 1, 0));
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;

		datas = vector<int>(N);
		dp = vector<vector<vector<int>>>(2, vector<vector<int>>(N, vector<int>(N, 0)));

		for (int i = 0; i < N; i++) {
			cin >> datas[i];
		}

		cout << Game(0, N - 1, 0) << "\n";
	}
	return 0;
}