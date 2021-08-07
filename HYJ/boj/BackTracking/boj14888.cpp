#include <iostream>
#include <vector>

using namespace std;

vector<long long> nums;
long long Max = -2147483647;
long long Min = 2147483647;
int N;


void DFS(int index, long long num, int a, int b, int c, int d) {
	// √º≈©¿Œ
	if (index + 1 == N &&a == 0 && b == 0 && c == 0 && d == 0) {
		if (Max < num) {
			Max = num;
		}

		if (Min > num) {
			Min = num;
		}

		return;
	}


	if (a > 0) {
		DFS(index + 1, num + nums[index + 1], a - 1, b, c, d);
	}
	if (b > 0) {
		DFS(index + 1, num - nums[index + 1], a, b - 1, c, d);
	}
	if (c > 0) {
		DFS(index + 1, num * nums[index + 1], a, b, c - 1, d);
	}

	if (d > 0) {
		DFS(index + 1, num / nums[index + 1], a, b, c, d - 1);
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N; 
	nums = vector<long long>(N);

	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	DFS(0, nums[0], a, b, c, d);

	cout << Max << "\n" << Min << "\n";

	return 0;
}