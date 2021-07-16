#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int N, M;
vector<long long> v;

int result, maxbit;
long long a = 1;

int countBit(long long bit) {
	int result = 0;
	while (bit) {
		result += bit & 1;
		bit >>= 1;
	}
	return result;
}
void DFS(int index, long long check_num, int count) {

	// 전부의 곡을 연주하는 것이아니라!!,
	// 가능한 최대의 곡을 연주해야되는 것.!!!!
	int Y = countBit(check_num);

	if (maxbit < Y) {
		maxbit = Y;
		result = count;
	}
	else if (maxbit == Y) {
		result = min(result, count);
	}

	if (index >= N) return;

	DFS(index + 1, check_num | v[index + 1], count + 1);
	DFS(index + 1, check_num, count);
	
}

int main() {

	cin >> N >> M;

	
	v = vector<long long>(N + 1);

	for (int i = 0; i < M; i++) {
		a *= 2;
	}

	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		string check;
		cin >> check;

		long long num_check = 0;

		for (int j = 0; j < check.length(); j++) {
			if (check[j] == 'Y') {
				num_check = (num_check | (1LL << j));
			}
		}

		v[i] = num_check;
	}

	for (int i = 1; i <= N; i++) {
		DFS(i, v[i], 1);
	}

	if (result== 0) {
		cout << -1 << "\n";
	}
	else {
		cout << result;
	}

	return 0;
}