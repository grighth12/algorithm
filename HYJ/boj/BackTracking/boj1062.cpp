#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v;

int result = 0;

int checked;
void DFS(int index, int count) {

	if (index > 26) return;
	
	if (count == M) {
		int cnt = 0;
		for (int str : v) {
			if ((str & checked) == str) cnt++;
		}

		result = max(result, cnt);
	}

	for (int i = index; i < 26; i++) {
		if ((checked & (1 << i)) == 0) {
			checked |= (1 << i);
			DFS(i + 1, count + 1);
			checked &= ~(1 << i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	v = vector<int>(N);

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		int check = 0;
		for (int j = 0; j < str.length(); j++) {
			check |= (1 << str[j] - 'a');
		}

		v[i] = check;
	}
	checked = (1 << ('a' - 'a')) | (1 << ('n' - 'a')) | (1 << ('t' - 'a')) | (1 << ('i' - 'a')) | (1 << ('c' - 'a'));


	if (M < 5 || M == 26) {
		cout << (M == 26 ? N : 0) << endl;
		return 0;
	}
	else {
		DFS(0, 5);
		cout << result << "\n";

	}

	return 0;

}