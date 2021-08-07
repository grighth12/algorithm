#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	long long T;
	cin >> T;
	int N, M;

	cin >> N;

	vector<int> A(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> M;
	vector<int> B(M, 0);
	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}

	// �κ� ���� �迭 ����
	vector<long long> A_sub;
	vector<long long> B_sub;

	
	for (int i = 0; i < N; i++) {
		long long sum = 0;
		for (int j = i; j < N; j++) {
			sum += A[j];
			A_sub.push_back(sum);
		}
	}
	
	for (int i = 0; i < M; i++) {
		long long sum = 0;
		for (int j = i; j < M; j++) {
			sum += B[j];
			B_sub.push_back(sum);
		}
	}
	
	// ����
	sort(A_sub.begin(), A_sub.end());
	sort(B_sub.begin(), B_sub.end(), cmp);

	
	// �� ������ ����
	
	int A_index = 0;
	int B_index = 0;
	long long count = 0;
	while (true) {
		// ���� 
		if (A_index == A_sub.size() || B_index == B_sub.size()) break;

		// ���� ����
		long long target = T - A_sub[A_index];
		long long currentA = A_sub[A_index];
		
		if (target == B_sub[B_index]) {
			//cout << A_sub[A_index] << " " << B_sub[B_index] << "\n";
			// A�� B �߿� ���� �͵��� � �ִ��� ����
			long long a_count = 0;
			long long b_count = 0;

			while (A_index < A_sub.size() && A_sub[A_index] == currentA) {
				a_count++;
				A_index++;
			}

			while (B_index < B_sub.size() && B_sub[B_index] == target) {
				b_count++;
				B_index++;
			}

			count += (a_count * b_count);

		}
		else if (target > B_sub[B_index]) {
			A_index++;
		}
		else {
			B_index++;
		}
	}
	
	cout << count;
	
	return 0;

}