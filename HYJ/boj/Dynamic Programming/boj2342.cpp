#include <iostream>
#include <vector>

using namespace std;

vector<int> datas;
vector<vector<vector<int>>> dp;
int N;
// DP[���� ����][���� �� ��ġ] [������ �� ��ġ]
// DP�� ����Ž���̴�!! ������ ����Ž�� ���������, ����ġ�⸦ ���ؼ� �ð��� ���̴°��̴�.

int cost(int from, int to) {
	// 0���� ����� 2
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
	// �� ������� ����
	if (step == N) {
		return 0;
	}

	// ���ߴ°�?
	if (dp[step][left][right] != 0) return dp[step][left][right];

	// ���� ����
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