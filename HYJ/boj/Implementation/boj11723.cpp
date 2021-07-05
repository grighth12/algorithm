#include <iostream>
#include <string>
#include <cmath>


using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int M;

	cin >> M;

	int set = 0;
	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;

		if (str == "add") {
			int num;
			cin >> num;
			set = set | (1 << (num - 1));
		}
		else if (str == "check") {
			int num;
			cin >> num;

			int temp = set & (1 << (num - 1));
			if (temp == 0) {
				cout << "0\n";
			}
			else {
				cout << "1\n";
			}
		}
		else if (str == "remove") {
			int num;
			cin >> num;
			set = set & ~(1 << (num - 1));
		}
		else if (str == "toggle") {
			int num;
			cin >> num;

			int temp = set & (1 << (num - 1));
			if (temp == 0) {
				set = set | (1 << (num - 1));
			}
			else {
				set = set & ~(1 << (num - 1));
			}
		}
		else if (str == "all") {
			set = pow(2, 21) - 1;
		}
		else if (str == "empty") {
			set = 0;
		}
	}

	return 0;
}