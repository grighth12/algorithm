#include <iostream>
#include <map>

using namespace std;

int main() {
	int N;
	cin >> N;

	map<string, int> m;
	int count = 0;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		if (m.find(str) == m.end()) {
			m.insert(make_pair(str, 1));
		}
		else {
			m[str]++;
		}

		if (m[str] > count) {
			count = m[str];
		}
	}

	for (auto iter : m) {
		if (iter.second == count) {
			cout << iter.first;
			break;
		}

	}

	return 0;
}