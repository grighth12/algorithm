#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, S;
	cin >> N >> S;

	vector<int> v(N +1, 0);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	int left = 0;
	int right = 0;
	int length = 2000000000;
	long long sum = v[0];
	while (left < N && right < N) {

		/*
		// 여길 고쳐야됨.. sum 값을 기억하도록 만들자!
		for (int i = left; i <= right; i++) {
			sum += v[i];
		}
		*/

		if (sum >= S) {
			length = min(length, right - left + 1);
			sum -= v[left++];
		}
		else if (sum < S) {
			sum += v[++right];
		}
	}

	if (length == 2000000000) {
		cout << 0 << "\n";
	}
	else {
		cout << length;
	}
	return 0;
}