#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_pq;
		priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> max_pq;

		int k;

		cin >> k;
		// 삭제 되었는가 판단하는 벡터
		vector<bool> deleted(k, false);

		for (int i = 0; i < k; i++) {
			char ch;
			int num;
			cin >> ch >> num;

			if (ch == 'I') {
				min_pq.push(make_pair(num, i));
				max_pq.push(make_pair(num, i));
			}
			else if (ch == 'D') {
				if (!min_pq.empty() && !max_pq.empty()) {
					if (num == -1) {
						deleted[min_pq.top().second] = true;
						min_pq.pop();
					}
					else if (num == 1) {
						deleted[max_pq.top().second] = true;
						max_pq.pop();
					}
				}

				// 삭제 된것들을 업데이트 시켜주기 
				while (!min_pq.empty() && deleted[min_pq.top().second]) {
					min_pq.pop();
				}

				while (!max_pq.empty() && deleted[max_pq.top().second]) {
					max_pq.pop();
				}
			}
		}

		// 삭제 된것들을 업데이트 시켜주기 
		while (!min_pq.empty() && deleted[min_pq.top().second]) {
			min_pq.pop();
		}

		while (!max_pq.empty() && deleted[max_pq.top().second]) {
			max_pq.pop();
		}

		if (min_pq.empty() && max_pq.empty()) {
			cout << "EMPTY" << "\n";
		}
		else {
			cout << max_pq.top().first << " " << min_pq.top().first << "\n";
		}

	}

	return 0;

}
