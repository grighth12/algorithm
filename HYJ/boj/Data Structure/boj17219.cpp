#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	map<string, string> m;
	int N, M;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string str1, str2;

		cin >> str1 >> str2;

		m.insert(make_pair(str1, str2));
	}

	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;
		cout << m[str] << "\n";
	}

	return 0;
}
