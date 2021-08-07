#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> m;

vector<vector<bool>> check;
vector<vector<bool>> check2;

int N;

int cnt = 0;
int cnt2 = 0;
bool isPossible(int y, int x) {
	return 0 <= x && x < N && 0 <= y && y < N;
}

void DFS(int y, int x, char last) {
	// 목적지인가?
	if (last != m[y][x]) {
		return;
	}
	
	// 체크인
	check[y][x] = true;

	int mx[4] = { 1,-1,0,0 };
	int my[4] = { 0,0,1,-1 };
	// 탐색할 수 있는가?
	for (int i = 0; i < 4; i++) {
		int tx = mx[i] + x;
		int ty = my[i] + y;

		// 방문할 수 있는가?
		if (isPossible(ty, tx) && !check[ty][tx]) {
			// 방문
			DFS(ty, tx, m[y][x]);
		}
	}

}

void DFS2(int y, int x, char last) {
	// 목적지인가?
	if ((last == 'B' && last != m[y][x]) || (last != 'B' && m[y][x] != 'R' && m[y][x] != 'G')) {
		return;
	}

	// 체크인
	check2[y][x] = true;

	int mx[4] = { 1,-1,0,0 };
	int my[4] = { 0,0,1,-1 };
	// 탐색할 수 있는가?
	for (int i = 0; i < 4; i++) {
		int tx = mx[i] + x;
		int ty = my[i] + y;

		// 방문할 수 있는가?
		if (isPossible(ty, tx) && !check2[ty][tx]) {
			// 방문
			DFS2(ty, tx, m[y][x]);
		}
	}

}

int main() {
	
	cin >> N;

	m = vector<string>(N);
	check = vector<vector<bool>>(N, vector<bool>(N, false));
	check2 = vector<vector<bool>>(N, vector<bool>(N, false));

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		m[i] = str;
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!check[i][j]) {
				cnt++;
				DFS(i, j, m[i][j]);
			}

			if (!check2[i][j]) {
				cnt2++;
				DFS2(i, j, m[i][j]);
			}
		}
	}

	cout << cnt << " " << cnt2;

	return 0;
}