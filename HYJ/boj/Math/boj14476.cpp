#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

void print(vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	vector<int> nums(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	vector<int> l2r(N, 0);
	vector<int> r2l(N, 0);
	
	l2r[0] = nums[0];

	for (int i = 1; i < N; i++) {
		l2r[i] = gcd(l2r[i - 1], nums[i]);
	}

	r2l[N - 1] = nums[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		r2l[i] = gcd(r2l[i + 1], nums[i]);
	}
	/*
	print(nums);
	print(l2r);
	print(r2l);
	*/

	int BigGCD = -1;
	int sub_num = 0;

	for (int i = 0; i < N; i++) {
		int k = nums[i];

		int left_index = i - 1;
		int right_index = i + 1;
		
		int GCD;
		if (left_index < 0) {
			GCD = r2l[1];
		}
		else if (right_index >= N) {
			GCD = l2r[N - 2];
		}
		else {
			GCD = gcd(l2r[left_index], r2l[right_index]);
		}

		if (k % GCD != 0) {
			if (BigGCD < GCD) {
				BigGCD = GCD;
				sub_num = k;
			}
		}
	}

	if (BigGCD == -1) {
		cout << -1;
	}
	else {
		cout << BigGCD << " " << sub_num;
	}


	return 0;
}