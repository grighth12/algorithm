#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 200000000
using namespace std;

vector<vector<int>> dp; 
vector<int> ip;

int DivideConquere(int start, int end) {
	// 1개원소일 경우에는 바꿔줄 필요가 없다.
	if (start == end) return 0;

	// 이미 구해놨다면, 출력한다.
	if (dp[start][end] != MAX) return dp[start][end];

	// 구하지 못하였다면, 왼쪽 구간 오른쪽 구간을 나누어서 계산한다.
	int ret = MAX;
	for (int i = start; i < end; i++) {
		int left = DivideConquere(start, i);
		int right = DivideConquere(i + 1, end);
		
		// 만약 두 구간에 전구색이 같다면 바꿔줄 필요가 없다.
		if (ip[start] == ip[i + 1]) {
			ret = min(ret, left + right);
		}
		else {// 두 구간에 전구색이 다르다면 바꿔줘야된다.
			ret = min(ret, left + right + 1);
		}
	}

	return dp[start][end] = ret;
}

int main() {
	int N, K;

	cin >> N >> K;
	ip = vector<int>(N + 1, 0);

	dp = vector<vector<int>>(N + 1, vector<int>(N + 1, MAX));

	for (int i = 1; i <= N; i++) {
		cin >> ip[i];
	}
	DivideConquere(1, N);
	cout << dp[1][N];

	return 0;
}