#include <iostream>
#include <vector>

using namespace std;

// �����̵� ������ ��� 
// �� ������ ����� ����Ѵ�.
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