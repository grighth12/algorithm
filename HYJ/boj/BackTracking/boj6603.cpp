#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;
vector<bool> checks;

int T;

void DFS(int index, int count) {
	// 체크인
	checks[index] = true;

	// 목적지인가?
	if (count == 6) {
		for (int i = 0; i < T; i++) {
			if (checks[i]) cout << nums[i] << " ";
		}
		cout << "\n";
		checks[index] = false;
		return;
	}

	// 순회할 수 있는가?
	// 진짜로 방문할 수 있는가?
	for (int i = index + 1; i < T; i++) {
		// 방문
		DFS(i, count + 1);
	}
	// 체크아웃
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