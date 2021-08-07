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

	// �Է��� �޴� ��� �ٷ� dp�� �����ؾߵɵ�.

	for (int i = 0; i < N; i++) {
		// �����̵� ������� �Է��� ���� ��� ó���ϴ°� , �� ó���ϴ� ������ ���������� ����
		// �׸��� �� ������ ��Ҵ� �ٲ�� ���� �ǹ�
		for (int j = 0; j < 3; j++) {
			cin >> m[j];
		}

		// dp ó��
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