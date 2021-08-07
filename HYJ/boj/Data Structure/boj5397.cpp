#include <iostream>
#include <string>
#include <stack>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		string str;
		cin >> str;

		stack<char> front;
		stack<char> last;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '<') {
				if (!front.empty()) {
					last.push(front.top());
					front.pop();
				}
			}
			else if (str[i] == '>') {
				if (!last.empty()) {
					front.push(last.top());
					last.pop();
				}
			}
			else if (str[i] == '-') {
				if (!front.empty()) {
					front.pop();
				}
			}
			else {
				front.push(str[i]);
			}
		}

		while (!front.empty()) {
			last.push(front.top());
			front.pop();
		}

		while (!last.empty()) {
			cout << last.top();
			last.pop();
		}
		cout << "\n";

	}
	return 0;

}