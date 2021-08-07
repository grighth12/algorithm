#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> m;
int N, M;
int res = 0;
struct Point {
	int y;
	int x;
	Point(int y, int x){
		this->x = x;
		this->y = y;
	}
};

bool isPossible(int y, int x) {
	return 0 <= y && y < N && 0 <= x && x < M;
}


void BFS() {
	int mx[4] = { 0, 0, -1, 1 };
	int my[4] = { 1,-1, 0,0 };

	queue<Point> q;
	vector<vector<int>> check = vector<vector<int>>(N, vector<int>(M, 0));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			check[i][j] = m[i][j];
			if (check[i][j] == 2) {
				q.push(Point(i,j));
			}
		}
	}

	// 작업
	while (!q.empty()) {

		Point p = q.front();
		q.pop();

		// 체크인
		check[p.y][p.x] = 2;

		// 방문할 수 있는가?
		for (int i = 0; i < 4; i++) {
			int tx = p.x + mx[i];
			int ty = p.y + my[i];

			// 진짜로 방문 가능한가?
			if (isPossible(ty, tx) && check[ty][tx] == 0) {
				// 방문
				check[ty][tx] = 2;
				q.push(Point(ty, tx));
			}
		}
	}

	// 0의 개수 카운팅
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (check[i][j] == 0) {
				count++;
			}
		}
	}
	if (res < count) {
		res = count;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);


	cin >> N >> M;

	m = vector<vector<int>>(N, vector<int>(M, 0));

	vector<Point> zeros;
	vector<Point> virus;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> m[i][j];
			if (m[i][j] == 0) {
				zeros.push_back(Point(i, j));
			}
			if (m[i][j] == 2) {
				virus.push_back(Point(i, j));
			}
		}
	}

	for (int i = 0; i < zeros.size(); i++) {
		for (int j = i + 1; j < zeros.size(); j++) {
			for (int k = j + 1; k < zeros.size(); k++) {
				m[zeros[i].y][zeros[i].x] = 1;
				m[zeros[j].y][zeros[j].x] = 1;
				m[zeros[k].y][zeros[k].x] = 1;

				BFS();

				m[zeros[i].y][zeros[i].x] = 0;
				m[zeros[j].y][zeros[j].x] = 0;
				m[zeros[k].y][zeros[k].x] = 0;
			}
		}
	}
	cout << res;
	

	return 0;
}