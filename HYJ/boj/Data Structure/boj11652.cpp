#include <iostream>
#include <map>

using namespace std;

int main() {
	int N;

	cin >> N;

	map<long long, int> m;
	int count_max = 0;
	for (int i = 0; i < N; i++) {
		long long a;
		cin >> a;
		if (m.find(a) != m.end()) {
			m[a] += 1;
		}
		else {
			m.insert(make_pair(a, 1));
		}
		if (count_max < m[a]) {
			count_max = m[a];
		}
	}

	for (auto iter : m) {
		if (count_max == iter.second) {
			cout << iter.first;
			break;
		}
	}

	return 0;
}