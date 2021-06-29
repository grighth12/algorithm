#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N, M, B;

	cin >> N >> M >> B;

	vector<vector<int>> map(N, vector<int>(M, 0));

	int min = INT_MAX;
	int max = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];

			if (min > map[i][j]) {
				min = map[i][j];
			}
			if (max < map[i][j]) {
				max = map[i][j];
			}
		}
	}

	int low_time = INT_MAX;
	int highest_high = 0;

	for (int n = min; n <=max; n++) {
		int high = n;
		int delete_count = B;
		int add_count = 0;
		int time = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (high > map[i][j]) {
					add_count += (high - map[i][j]);
					time += (high - map[i][j]);
				}
				else if (high < map[i][j]) {
					delete_count += (map[i][j] - high);
					time += ((map[i][j] - high) * 2);
				}
			}
		}

		if (delete_count - add_count >= 0) {
			if (low_time > time) {
				low_time = time;
				highest_high = n;
			}

			if (low_time == time) {
				if (high < n)
					highest_high = n;
			}
		}
	}

	cout << low_time << " " << highest_high;

	return 0;
}