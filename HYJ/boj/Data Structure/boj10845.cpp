#include <iostream>
#include <vector>

using namespace std;

class Queue {
	vector<int> v;

public :
	void push(int x) {
		v.push_back(x);
	}

	int pop() {
		if (empty() == 1)  return -1;

		int front = v[0];

		v.erase(v.begin());

		return front;
	}

	int size() {
		return v.size();
	}

	int empty() {
		return v.size() == 0 ? 1 : 0;
	}

	int front() {
		if (empty() == 1) return -1;

		return v[0];
	}

	int back() {
		if (empty() == 1) return -1;

		return v[v.size() - 1];
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	Queue q;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		if (str == "push") {
			int a;
			cin >> a;
			q.push(a);
		}
		else if (str == "front") {
			cout << q.front() << "\n";
		}
		else if (str == "back") {
			cout << q.back() << "\n";
		}
		else if (str == "size") {
			cout << q.size() << "\n";
		}
		else if (str == "empty") {
			cout << q.empty() << "\n";
		}
		else if (str == "pop") {
			cout << q.pop() << "\n";
		}
	}

	return 0;
}