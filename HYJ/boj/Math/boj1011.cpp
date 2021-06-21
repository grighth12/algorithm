#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		long x, y;
		cin >> x >> y;
		long distance = y - x;
		long turn = 1;
		long position = 1;
		long step = 0;
		while (position < distance) {
			step++;

			turn++;
			position += step;
			if (position >= distance) break;

			turn++;
			position += step;
			if (position >= distance) break;
		}
		if (position > distance) {
			turn--;
		}

		cout << turn << "\n";

	}

	return 0;

}