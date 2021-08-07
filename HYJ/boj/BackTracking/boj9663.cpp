#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int Count = 0;
vector<int> m;

// m[y] = x��ǥ, y : y��ǥ (i)
bool check(int y) {
	for (int i = 0; i < y; i++) {
		// m[i] == m[y] �ǹ� �ڽ� ���� Queen�� �ִٴ� ��
		// abs(m[y] - m[i]) == (y - i) : ���� ���Ⱑ 1�Ǵ� -1 �̶�� 
		// �밢���� ���� �ִ� ���� �ǹ���.
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