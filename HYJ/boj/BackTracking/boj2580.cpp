#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> m;
vector<pair<int, int>> points;

int zero_num;
bool isFound = false;

bool isOkay(int y, int x) {
	bool result = true;

	bool nums[10] = { false };
	// 일직선 검사
	for (int i = 0; i < 9; i++) {
		if (m[y][i] != 0 && nums[m[y][i]]) {
			return false;
		}
		else {
			nums[m[y][i]] = true;
		}
	}
	// 세로 검사
	bool nums2[10] = { false };

	for (int i = 0; i < 9; i++) {
		if (m[i][x] != 0 && nums2[m[i][x]]) {
			return false;
		}
		else {
			nums2[m[i][x]] = true;
		}
	}

	// 9칸 검사

	bool nums3[10] = { false };
	int mx = x / 3;
	int my = y / 3;

	for (int i = 3 * my; i < 3 * my + 3; i++) {
		for (int j = 3 * mx; j < 3 * mx + 3; j++) {
			if (m[i][j] != 0 && nums3[m[i][j]]) {
				return false;
			}
			else {
				nums3[m[i][j]] = true;
			}
		}
	}

	return result;
}

void printMap() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << m[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
}

void DFS(int count) {
	// 공백이 없으면 출력
	if (count == zero_num) {
		printMap();
		exit(0);
	}
	else {
		for (int i = 1; i <= 9; i++) {
			m[points[count].first][points[count].second] = i;
			if (isOkay(points[count].first, points[count].second)) {
				DFS(count + 1);
			}
		}

		m[points[count].first][points[count].second] = 0;
		return;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	m = vector<vector<int>>(9, vector<int>(9, 0));

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int num;
			cin >> num;
			if (num == 0) {
				// points는 공백인 위치를 저장하는 벡터
				points.push_back(make_pair(i, j));
				zero_num++;
			}
			m[i][j] = num;
		}
	}
	
	DFS(0);

	return  0;

}