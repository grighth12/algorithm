#include <iostream>
#include <vector>

using namespace std;

vector<string> m;
vector<bool> alpha;
int ma = 0;
int R, C;

bool isPossible(int y, int x) {
	return 0 <= y && y < R && 0 <= x && x < C;
}

void DFS(int y, int x, int count) {
	int index = m[y][x] - 'A';
	int mx[4] = {1,-1,0,0};
	int my[4] = { 0,0,1,-1 };
	// 체크인
	alpha[index] = true;
	// 목적지인가?
	ma = max(ma, count);

	// 방문할 수 있는가?
	for (int i = 0; i < 4; i++) {
		int tx = mx[i] + x;
		int ty = my[i] + y;
		// 갈 수 있는가?
		if (isPossible(ty, tx)) {
			int tmp_index = m[ty][tx] - 'A';
			// 만약 새로 이동할 곳의 알파벳을 방문을 한 적이 없다면 방문 가능
			if (!alpha[tmp_index]) {
				// 방문
				DFS(ty, tx, count + 1);
			}
		}
	}
	
	// 체크아웃
	alpha[index] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	alpha = vector<bool>(26, false);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		string str;
		cin >> str;
		m.push_back(str);
	}

	DFS(0, 0, 1);

	cout << ma << "\n";

	return 0;
}