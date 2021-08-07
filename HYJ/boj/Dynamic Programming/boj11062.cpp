#include <iostream>
#include <vector>

using namespace std;

vector<int> datas;
vector<vector<vector<int>>> dp;

// DP Ǯ�� �� !!! : DP�� �� ��������'
// DP�� ������������ Ǯ ���� �ִ�. ���� �������� �����ϴ� ������ �غ���.
// DP[flag][start][end] : flag ����, start ~end ���̿��� �ٿ찡 ���� �ִ��� ���� 

int Game(int start, int end, int flag) {

	// ������ ����
	if (start == end) {
		// �ٿ��� ��
		if (flag == 0) {
			return dp[flag][start][end] = datas[start];
		}
		else {
			// ����� ��
			return dp[flag][start][end] = 0;
		}
	}

	//���ߴ°�?
	if (dp[flag][start][end] != 0) return  dp[flag][start][end];


	// ���� ����
	if (flag == 0) {
		// �ٿ� �϶�
		return dp[flag][start][end] = max(Game(start + 1, end, 1) + datas[start]
			, Game(start, end - 1, 1) + datas[end]);
	}
	else {
		// ��� �϶��� dp�� ���ǰ� (�ٿ�, ��� ������ ��)�ٿ��� �����̹Ƿ� 
		// �ٿ��� ������ �ּҰ����� ����� ������ �����ߵȴ�.
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