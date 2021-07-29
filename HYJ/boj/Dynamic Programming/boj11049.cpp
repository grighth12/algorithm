#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 2147483647

using namespace std;

struct Matrix {
	int r;
	int c;

	Matrix(int r, int c) {
		this->r = r;
		this->c = c;
	}
	Matrix() {
		r = 0;
		c = 0;
	}
};

vector<vector<int>> dp;
vector<Matrix> datas;
int DivideConqure(int start, int end) {
	if (start == end) return 0;

	if (dp[start][end] != MAX) {
		return dp[start][end];
	}

	int left, right;
	for (int i = start; i < end; i++) {
		// 왼쪽 부분 값 구하기
		left = DivideConqure(start, i);
		// 오른쪽 부분 값 구하기
		right = DivideConqure(i + 1, end);

		// 왼쪽 + 오른쪽 부분 값 그리고 부분들끼리의 합 계산하기
		dp[start][end] = min(dp[start][end], 
			left + right + (datas[start].r * datas[i].c * datas[end].c));

	}
	return dp[start][end];
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;

	datas = vector<Matrix>(N + 1);
	dp = vector<vector<int>>(N + 1, vector<int>(N + 1, MAX));
	for (int i = 1; i <= N; i++) {
		int r, c;
		cin >> r >> c;

		datas[i] = Matrix(r, c);
	}
	DivideConqure(1, N);
	cout << dp[1][N];

	return 0;
}