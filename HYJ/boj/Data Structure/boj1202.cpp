#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct JW {
	int value;
	int mass;

	JW(int mass, int value){
		this->value = value;
		this->mass = mass;
	}

	JW() {

	}
};

bool JW_cmp(JW a, JW b) {
	return a.mass < b.mass;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, K;

	cin >> N >> K;

	vector<JW> jewelry(N);
	vector<int> bags(K, 0);

	for (int i = 0; i < N; i++) {
		int m, v;
		cin >> m >> v;
		jewelry[i] = JW(m, v);
	}

	for (int i = 0; i < K; i++) {
		cin >> bags[i];
	}

	// 보석 무게순으로 오름차순, 가방도 사이즈 순으로 오름차순으로 정렬함.
	sort(jewelry.begin(), jewelry.end(), JW_cmp);
	sort(bags.begin(), bags.end());
	/*
	for (int i = 0; i < bags.size(); i++) {
		//cout << jewelry[i].mass << "\n";

		cout << bags[i] << "\n";
	}*/

	int jw_index = 0;
	priority_queue<long long, vector<long long>> pq;
	long long result = 0;
	for (int i = 0; i < bags.size(); i++) {
		while (true) {
			// 종료 조건
			if (jw_index >= jewelry.size())  break;

			if (jewelry[jw_index].mass <= bags[i]) {
				pq.push(jewelry[jw_index].value);
				jw_index++;
			}
			else {
				break;
			}
		}

		if (!pq.empty()) {
			result += pq.top();
			pq.pop();
		}
	}


	cout << result;

	return 0;
}