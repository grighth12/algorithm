#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Lumber(vector<long> v, long norm) {
	long sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > norm) {
			sum += (v[i] - norm);
		}
	}

	return sum;
}


int main() {
	int N, M;
	cin >> N >> M;

	vector<long> v(N, 0);

	long high = 0;
	long low = 0;
	long answer = 0;

	for (int i = 0; i < N; i++) {
		cin >> v[i];
		high = max(high, v[i]);
	}

	while (low <= high) {
		long mid = (high + low) / 2;
		long sum = Lumber(v, mid);
		if (sum >= M) {
			low = mid + 1;
			answer = mid;
		}
		else if (sum < M) {
			high = mid - 1;
		}
	}

	cout << answer;

	return 0;
}