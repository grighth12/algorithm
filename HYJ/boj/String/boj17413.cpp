#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 문자열 입력
	string str;
	getline(cin, str);

	// 스택과 큐 선언
	stack<char> s;
	queue<char> q;
	
	// 괄호 <가 열렸는지 체크
	bool isOpen = false;
	for (int i = 0; i < str.length(); i++) {
		// 만약 괄호가 열렸으면 큐를 사용한다.
		if (str[i] == '<') {
			isOpen = true;
			q.push(str[i]);
		}// 괄호가 닫혔으면 큐에 문자를 넣고 스택에 있는 것을 다 출력한 뒤 큐를 출력한다.
		else if (str[i] == '>') {
			isOpen = false;
			q.push(str[i]);

			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}
			while (!q.empty()) {
				cout << q.front();
				q.pop();
			}
		} else if(!isOpen){

			// 괄호가 열려있지 않으면, 스페이스가 나올때 까지 스택에 넣다가 스페이스면 스택에 있는거 다 출력
			if (str[i] != ' ') {
				s.push(str[i]);
			}
			else {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				cout << " ";
			}
		}
		else {
			q.push(str[i]);
		}
	}
	// 비어있는 스택을 출력한다.
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}

	return 0;
}