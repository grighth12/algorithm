#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 200000000
using namespace std;

vector<vector<int>> dp; 
vector<int> ip;

int DivideConquere(int start, int end) {
	// 1�������� ��쿡�� �ٲ��� �ʿ䰡 ����.
	if (start == end) return 0;

	// �̹� ���س��ٸ�, ����Ѵ�.
	if (dp[start][end] != MAX) return dp[start][end];

	// ������ ���Ͽ��ٸ�, ���� ���� ������ ������ ����� ����Ѵ�.
	int ret = MAX;
	for (int i = start; i < end; i++) {
		int left = DivideConquere(start, i);
		int right = DivideConquere(i + 1, end);
		
		// ���� �� ������ �������� ���ٸ� �ٲ��� �ʿ䰡 ����.
		if (ip[start] == ip[i + 1]) {
			ret = min(ret, left + right);
		}
		else {// �� ������ �������� �ٸ��ٸ� �ٲ���ߵȴ�.
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