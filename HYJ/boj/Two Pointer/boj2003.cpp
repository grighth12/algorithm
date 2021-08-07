#include <iostream>
#include <vector>

using namespace std;

// 슬라이딩 윈도우 기법 
// 투 포인터 기법을 사용한다.
int main() {
	int N, M;

	cin >> N >> M;

	vector<int> v(N,0);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	int left = 0;
	int right = 0;

	int count = 0;
	while (right < N && left < N) {
		int sum = 0;

		for (int i = left; i <= right; i++) {
			sum += v[i];
		}

		if (sum == M) {
			count++;
			left++;
		}
		else if (sum < M) {
			right++;
		}
		else if (sum > M) {
			left++;
		}
	}

	cout << count;
}