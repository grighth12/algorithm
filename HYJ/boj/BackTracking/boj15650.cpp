#include <iostream>

using namespace std;

int N, M;

void DFS(int num, int check, int count) {
	// num�� N���� Ŭ ���� �����Ƿ� Ŭ��� �������ش�.
	if (num > N) return;

	// count������ M�̶� ������, check�� �κ��� ����Ѵ�.
	if (count == M) {
		for (int i = 1; i <= N; i++) {
			if (((1 << i) & check) > 0) {
				cout << i << " ";
			}
		}
		cout << "\n";
		return;
	}

	DFS(num + 1, (check | (1 << (num + 1))), count + 1);
	DFS(num + 1, check, count);
}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		DFS(i, 1 << i, 1);
	}

	return 0;
}