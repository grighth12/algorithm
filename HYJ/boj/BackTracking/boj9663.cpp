#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int Count = 0;
vector<int> m;

// m[y] = x좌표, y : y좌표 (i)
bool check(int y) {
	for (int i = 0; i < y; i++) {
		// m[i] == m[y] 의미 자신 위에 Queen이 있다는 뜻
		// abs(m[y] - m[i]) == (y - i) : 만약 기울기가 1또는 -1 이라면 
		// 대각선에 퀸이 있는 것을 의미함.
		if (m[i] == m[y] || abs(m[y] - m[i]) == (y - i)) return false;
	}
	return true;
}


void DFS(int y) {
	if (y == N) {
		Count++;
		return;
	}
	else {
		for (int i = 0; i < N; i++) {
			m[y] = i;
			if (check(y))
				DFS(y + 1);
		}
	}
}


int main() {
	
	cin >> N;

	m = vector<int>(N, 0);
	DFS(0);

	cout << Count;

}