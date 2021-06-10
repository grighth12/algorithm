#include <iostream>
#include <map>
#include <string>
using namespace std;

int string_to_int(string str) {
	int n = 0;

	for (int i = 0; i < str.length(); i++) {
		n *= 10;
		n += (str[i] - '0');
	}

	return n;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	map<string, int> m1;
	map<int, string> m2;
	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		m1.insert(make_pair(str, i));
		m2.insert(make_pair(i, str));
	}


	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		if (str[0] >= '1' && str[0] <= '9') {
			int a = string_to_int(str);
			cout << m2.find(a)->second << "\n";
		}
		else {
			cout << m1.find(str)->second << "\n";
		}
	}
	return 0;

}