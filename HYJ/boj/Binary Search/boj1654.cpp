#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;

bool cmp(int a, int b) {
	return a > b;
}

bool countingLAN(vector<long> v, long long norm) {
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += (v[i] / norm);
	}

	return sum >= K;
}

int main() {
	cin >> N >> K;
	vector<long> v(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), cmp);
	
	// 가장 긴 길이
	long long high = v[0];
	long long low = 1;
	long long result = 0;

	while (low <= high) {
		long long mid = (low + high) / 2;
		// 만약 자르는게 가능하면, 길이를 늘리는 방안도 고려할 수가 있다.
		if (countingLAN(v, mid)) {
			// 자르는 길이를 늘려서 result보다 크다면 교체
			if (result < mid)
				result = mid;
			low = mid + 1;
		}
		// 자르는게 불가능하면, 길이를 줄인다.
		else {
			high = mid - 1;
		}
	}
	
	cout << result;

	return 0;

}