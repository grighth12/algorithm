#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(long long a, long long b) {
	return b < a;
}

int main() {
	int N;
	cin >> N;

	vector<vector<long long>> v(N, vector<long long>(4, 0));


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> v[i][j];
		}
	}

	vector<long long> A;
	vector<long long> B;


	for (int i = 0; i < N; i++) {
		long long temp = v[i][0];
		long long temp2 = v[i][2];
		for (int j = 0; j < N; j++) {
			A.push_back(temp + v[j][1]);
			B.push_back(temp2 + v[j][3]);
		}
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), cmp);

	// 투포인터 알고리즘 작성
	long long a_index = 0;
	long long b_index = 0;
	long long count = 0;

	while (a_index < A.size() && b_index < B.size()) {
		long long currentA = A[a_index];
		long long currentB = B[b_index];
		
		if (currentA + currentB == 0) {
			long long a_count = 0;
			long long b_count = 0;

			while (currentA == A[a_index]) {
				a_count++;
				a_index++;

				if (a_index == A.size())break;
			}

			while (currentB == B[b_index]) {
				b_count++;
				b_index++;

				if (b_index == B.size()) break;
			}

			count += (a_count * b_count);

		}
		else if (currentA + currentB > 0) {
			b_index++;
		}
		else if (currentA + currentB < 0) {
			a_index++;
		}

		if (a_index == A.size() || b_index == B.size()) break;
	}


	cout << count;

	return 0;
}