#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C;

struct Position {
	int y;
	int x; 
	char type;
	Position(int y, int x, char type) {
		this->x = x;
		this->y = y;
		this->type = type;
	}

	Position() {

	}
};

bool isMap(int y, int x) {
	return y >= 0 && y < R && x >= 0 && x < C;
}

void PrintMap(vector<vector<char>> v) {

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> R >> C;
	
	int mx[4] = { 0,0,-1,1 };
	int my[4] = { -1,1,0,0 };

	vector<vector<char>> v(R, vector<char>(C, 0));
	vector<vector<int>> dp(R, vector<int>(C, 0));

	queue<Position> q;

	Position sp;
	// �Էº�
	for (int i = 0; i < R; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			v[i][j] = str[j];

			if (v[i][j] == '*') {
				q.push(Position(i, j, '*'));
			}
			else if (v[i][j] == 'S') {
				sp = Position(i, j, 'S');
				dp[i][j] = 1;
			}
		}
	}

	q.push(sp);


	bool isFound = false;

	while (!q.empty()) {
		//1. ť���� ������
		Position p= q.front();
		q.pop();

		//2. ������ �ΰ�?
		if (p.type == 'D') {
			cout << dp[p.y][p.x] - 1;
			isFound = true;
			break;
		}

		//3. �湮�� �� �ִ� ���� ��ȸ
		for (int i = 0; i < 4; i++) {
			int tx = mx[i] + p.x;
			int ty = my[i] + p.y;
			//4. �� �� �ִ°�?
			if (isMap(ty, tx)) {
				if (p.type == '*') {
					//5. üũ��
					if (v[ty][tx] == '.' || v[ty][tx] == 'S') {
						v[ty][tx] = '*';
						// 6. ť�� ����
						q.push(Position(ty, tx, '*'));
					}
				}
				else {
					if ((v[ty][tx] == '.' || v[ty][tx] == 'D' ) && dp[ty][tx] == 0) {
						dp[ty][tx] = dp[p.y][p.x] + 1;

						q.push(Position(ty, tx, v[ty][tx]));
					}
				}
			}
		}
		
	}


	if (!isFound) {
		cout << "KAKTUS" << "\n";
	}

	return 0;

}