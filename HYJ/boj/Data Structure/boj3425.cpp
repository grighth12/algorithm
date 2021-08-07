#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cmath>
//#include <bits/stdc++.h>  이건 마법의 헤더파일 이거쓰면 다됨

using namespace std;

const long long RANGE = 1000000000;

struct Command {
public:
	string command;
	long long parameter;

	Command(string command, int parameter) {
		this->command = command;
		this->parameter = parameter;
	}
};


class GoStack {
	stack<long long> s;

public :
	bool NUMX(long long x) {
		s.push(x);
		return true;
	}

	bool POP() {
		if (s.empty()) return false;
		else {
			s.pop();
			return true;
		}
	}

	bool INV() {
		if (s.empty()) return false;
		else {
			long long temp = s.top();
			s.pop();
			temp = -temp;
			
			if (temp > RANGE) return false;

			s.push(temp);
			return true;
		}
	}

	bool DUP() {
		if (s.empty()) return false;
		else {
			s.push(s.top());
			return true;
		}
	}


	bool SWP() {
		if (s.size() < 2) return false;
		else {
			long long temp = s.top();
			s.pop();
			long long temp2 = s.top();
			s.pop();
			s.push(temp);
			s.push(temp2);
			return true;
		}
	}

	bool ADD() {
		if (s.size() < 2) return false;
		else {
			long long sum = s.top();
			s.pop();
			sum += s.top();
			s.pop();

			if (abs(sum) > RANGE) return false;

			s.push(sum);
			return true;
		}
	}

	bool SUB() {
		if (s.size() < 2) return false;
		else {
			long long result = 0;
			long long temp = s.top();
			s.pop();
			long long temp2 = s.top();
			s.pop();

			result = temp2 - temp;

			if (abs(result) > RANGE) return false;

			s.push(result);
			return true;
		}
	}

	bool MUL() {
		if (s.size() < 2) return false;
		else {
			long long temp = s.top();
			s.pop();
			long long temp2 = s.top();
			s.pop();
			long long result = temp * temp2;

			if (abs(result) > RANGE) return false;

			s.push(result);
			return true;
		}
	}

	bool DIV() {
		if (s.size() < 2) return false;
		else {
			long long temp = s.top();
			s.pop();

			if (temp == 0) return false;

			long long temp2 = s.top();
			s.pop();
			long long result = temp2 / temp;
			if (abs(result) > RANGE) return false;
			
			s.push(result);

			return true;
		}
	}

	bool MOD() {
		if (s.size() < 2) return false;
		else {
			long long temp = s.top();
			s.pop();

			if (temp == 0) return false;

			long long temp2 = s.top();
			s.pop();
			long long result = temp2  % temp;

			if (abs(result) > RANGE) return false;

			s.push(result);

			return true;
		}
	}

	int size() {
		return s.size();
	}

	long long top() {
		return s.top();
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	bool working = true;
	while (working) {
		vector<Command> v;
		bool programm_input = true;

		// 프로그램 입력 부분
		while (programm_input) {
			string str;
			cin >> str;
			if (str == "QUIT") {
				working = false;
				break;
			}
			else if (str == "NUM") {
				long long a;
				cin >> a;
				v.push_back(Command("NUM", a));
			}
			else if (str == "POP") {
				v.push_back(Command("POP", 0));
			}
			else if (str == "INV") {
				v.push_back(Command("INV", 0));
			}
			else if (str == "DUP") {
				v.push_back(Command("DUP", 0));
			}
			else if (str == "SWP") {
				v.push_back(Command("SWP", 0));
			}
			else if (str == "ADD") {
				v.push_back(Command("ADD", 0));
			}
			else if (str == "SUB") {
				v.push_back(Command("SUB", 0));
			}
			else if (str == "MUL") {
				v.push_back(Command("MUL", 0));
			}
			else if (str == "DIV") {
				v.push_back(Command("DIV", 0));
			}
			else if (str == "MOD") {
				v.push_back(Command("MOD", 0));
			}
			else if (str == "END") {
				programm_input = false;
			}
		}

		if (!working) break;
		// 숫자 입력부분
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			GoStack s;
			long long a;
			cin >> a;

			s.NUMX(a);
			bool isError = false;
			for (int j = 0; j < v.size(); j++) {
				if (v[j].command == "NUM") {
					s.NUMX(v[j].parameter);
				}
				else if (v[j].command == "POP") {
					if (!s.POP()) {
						isError = true;
						break;
					}
				}
				else if (v[j].command == "INV") {
					if (!s.INV()) {
						isError = true;
						break;
					}
				}
				else if (v[j].command == "DUP") {
					if (!s.DUP()) {
						isError = true;
						break;
					}
				}
				else if (v[j].command == "SWP") {
					if (!s.SWP()) {
						isError = true;
						break;
					}
				}
				else if (v[j].command == "ADD") {
					if (!s.ADD()) {
						isError = true;
						break;
					}
				}
				else if (v[j].command == "SUB") {
					if (!s.SUB()) {
						isError = true;
						break;
					}
				}
				else if (v[j].command == "MUL") {
					if (!s.MUL()) {
						isError = true;
						break;
					}
				}
				else if (v[j].command == "DIV") {
					if (!s.DIV()) {
						isError = true;
						break;
					}
				}
				else if (v[j].command == "MOD") {
					if (!s.MOD()) {
						isError = true;
						break;
					}
				}
			}

			if (isError || s.size() != 1) {
				cout << "ERROR" << "\n";
			}
			else {
				cout << s.top() << "\n";
			}
		}

		cout << "\n";
	}
}