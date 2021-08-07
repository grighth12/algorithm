#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	// ���ڿ� �Է�
	string str;
	getline(cin, str);

	// ���ð� ť ����
	stack<char> s;
	queue<char> q;
	
	// ��ȣ <�� ���ȴ��� üũ
	bool isOpen = false;
	for (int i = 0; i < str.length(); i++) {
		// ���� ��ȣ�� �������� ť�� ����Ѵ�.
		if (str[i] == '<') {
			isOpen = true;
			q.push(str[i]);
		}// ��ȣ�� �������� ť�� ���ڸ� �ְ� ���ÿ� �ִ� ���� �� ����� �� ť�� ����Ѵ�.
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

			// ��ȣ�� �������� ������, �����̽��� ���ö� ���� ���ÿ� �ִٰ� �����̽��� ���ÿ� �ִ°� �� ���
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
	// ����ִ� ������ ����Ѵ�.
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}

	return 0;
}