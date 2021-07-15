#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int N, M;

vector<vector<int>> m;
int DFS(int y, int x, int type) {
	if (y < 0 || y >= N || x < 0 || x >= M) return 0;
	if (m[y][x] == 0) return 0;

	// type 은 부모 타일 타입. 1: | , 2 : - ,
	if (type == 0) {
		if (m[y][x] == 1) {
			m[y][x] = 0;
			DFS(y + 1, x, 1);
			return 1;
		}
		else if(m[y][x] == 2) {
			DFS(y, x + 1, 2);
			m[y][x] = 0;
			return 1;
		}
	}
	else if (type == 1 && m[y][x] == 1) {
		DFS(y + 1, x, 1);
		m[y][x] = 0;
	}
	else if (type == 2 && m[y][x] == 2) {
		DFS(y, x + 1, 2);
		m[y][x] = 0;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio
	int count = 0;

	cin >> N >> M;

	m = vector<vector<int>>(N, vector<int>(M, 0));
	stack<int> s;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			if (str[j] == '-') {
				m[i][j] = 2;
			}
			else if (str[j] == '|') {
				m[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			count += DFS(i, j, 0);
		}
	}

	cout << count;

	return 0;
}