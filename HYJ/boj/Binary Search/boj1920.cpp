#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N;

	vector<long long> v(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;

		int low = 0;
		int high = N - 1;
		bool isHere = false;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (v[mid] > a) {
				high = mid - 1;
			}
			else if (v[mid] < a) {
				low = mid + 1;
			}
			else {
				isHere = true;
				break;
			}
		}
		if (isHere) {
			cout << "1\n";
		}
		else {
			cout << "0\n";
		}
	}

	return 0;

}