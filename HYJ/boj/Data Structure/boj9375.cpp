#include <iostream>
#include <map>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		map<string, int> m;
		int n;
		cin >> n;
		if (n == 0) {
			cout << 0 << "\n";
			continue;
		}
		for (int i = 0; i < n; i++) {
			string str, str2;
			cin >> str >> str2;

			if (m.find(str2) != m.end()) {
				m[str2]++;
			}
			else {
				m.insert(make_pair(str2, 1));
			}
		}
		int sum = 1;
		for (auto iter = m.begin(); iter != m.end(); iter++) {
			sum = sum * (iter->second + 1);
		}

		cout << sum - 1 << "\n";
	}

	return 0;
}