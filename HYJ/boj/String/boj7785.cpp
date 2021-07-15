#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	int N;

	cin >> N;

	set<string, greater<string>> s;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		string op;
		cin >> op;
		if (op == "enter")
		{
			s.insert(str);
		}
		else if (op == "leave") {
			s.erase(s.find(str));
		}
	}

	for (auto iter : s) {
		cout << iter << "\n";
	}
	
	return 0;
}