#include <iostream>
#include <vector>

using namespace std;

vector<int> datas;
vector<vector<vector<int>>> dp;
int N;
// DP[밟은 스탭][왼쪽 발 위치] [오른쪽 발 위치]
// DP는 완전탐색이다!! 하지만 완전탐색 기반이지만, 가지치기를 통해서 시간을 줄이는것이다.

int cost(int from, int to) {
	// 0에서 출발은 2
	if (from == 0) {
		return 2;
	}
	else if (from == to) {
		return 1;
	}
	else if (abs(from - to) == 2) {
		return 4;
	}
	else {
		return 3;
	}
}


int Game(int step, int left, int right) {
	// 다 밟았으면 종료
	if (step == N) {
		return 0;
	}

	// 구했는가?
	if (dp[step][left][right] != 0) return dp[step][left][right];

	// 게임 진행
	int left_cost = cost(left, datas[step]) + Game(step+1, datas[step], right) ;
	int right_cost = cost(right, datas[step]) + Game(step + 1,left , datas[step]);

	return dp[step][left][right] = min(left_cost, right_cost);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (true) {
		int a;
		cin >> a;

		if (a == 0) break;

		datas.push_back(a);
	}

	N = datas.size();

	dp = vector<vector<vector<int>>>(N, vector<vector<int>>(5, vector<int>(5, 0)));

	cout << Game(0, 0, 0);

	return 0;
}