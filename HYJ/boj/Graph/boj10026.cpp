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
	// �������ΰ�?
	if (last != m[y][x]) {
		return;
	}
	
	// üũ��
	check[y][x] = true;

	int mx[4] = { 1,-1,0,0 };
	int my[4] = { 0,0,1,-1 };
	// Ž���� �� �ִ°�?
	for (int i = 0; i < 4; i++) {
		int tx = mx[i] + x;
		int ty = my[i] + y;

		// �湮�� �� �ִ°�?
		if (isPossible(ty, tx) && !check[ty][tx]) {
			// �湮
			DFS(ty, tx, m[y][x]);
		}
	}

}

void DFS2(int y, int x, char last) {
	// �������ΰ�?
	if ((last == 'B' && last != m[y][x]) || (last != 'B' && m[y][x] != 'R' && m[y][x] != 'G')) {
		return;
	}

	// üũ��
	check2[y][x] = true;

	int mx[4] = { 1,-1,0,0 };
	int my[4] = { 0,0,1,-1 };
	// Ž���� �� �ִ°�?
	for (int i = 0; i < 4; i++) {
		int tx = mx[i] + x;
		int ty = my[i] + y;

		// �湮�� �� �ִ°�?
		if (isPossible(ty, tx) && !check2[ty][tx]) {
			// �湮
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