#include <iostream>

using namespace std;

int N, M;

void DFS(int num, int check, int count) {
	// num가 N보다 클 수가 없으므로 클경우 리턴해준다.
	if (num > N) return;

	// count개수가 M이랑 같으면, check된 부분을 출력한다.
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