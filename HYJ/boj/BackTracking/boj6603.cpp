#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;
vector<bool> checks;

int T;

void DFS(int index, int count) {
	// üũ��
	checks[index] = true;

	// �������ΰ�?
	if (count == 6) {
		for (int i = 0; i < T; i++) {
			if (checks[i]) cout << nums[i] << " ";
		}
		cout << "\n";
		checks[index] = false;
		return;
	}

	// ��ȸ�� �� �ִ°�?
	// ��¥�� �湮�� �� �ִ°�?
	for (int i = index + 1; i < T; i++) {
		// �湮
		DFS(i, count + 1);
	}
	// üũ�ƿ�
	checks[index] = false;
}

int main() {
	while (true) {
		cin >> T;
		if (T == 0) {
			break;
		}

		nums = vector<int>(T, 0);
		checks = vector<bool>(T, false);

		for (int i = 0; i < T; i++) {
			cin >> nums[i];
		}

		for (int i = 0; i < T; i++) {
			DFS(i, 1);
		}
		cout << "\n";

	}
}