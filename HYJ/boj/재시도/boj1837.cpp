#include <iostream>
#include <vector>
#include <string>

using namespace std;

string P;
bool checkIsBad(int x) {
	int ret = 0;
	for (int i = 0; i < P.length(); i++) {
		ret = (ret * 10 + (P[i] - '0')) % x;
	}
	if (ret == 0) {
		return true;
	}
	else {
		return false;
	}
}


int main() {
	
	int K;
	cin >> P;
	cin >> K;

	vector<bool> primes(1000000 + 1, false);
	// 에라스토테라스의 체 구현


	for (int i = 2; i <= 1000000; i++) {
		if (!primes[i]) {
			for (int j = 2; i* j <= K; j++) {
				primes[i *j] = true;
			}
		}
	}
	
	/*
	bool isGood = false;
	int badcount = 0;
	for (int i = 2; i <= 1000000; i++) {
		if (!primes[i]) {
			if (P % i == 0) {
				int q = P / i;
				if (q < K || i < K) {
					isGood = false;
					badcount = min(q, i);
				}
				else {
					isGood = true;
				}
				break;
			}
		}
	}
	*/
	bool isGood = false;
	int badcount = 0;
	for(int i = 2; i <= 1000000; i++){
		if (!primes[i]) {
			if (checkIsBad(i)) {
				isGood = true;
				break;
			}
			else {
				isGood = false;
				badcount = i;

			}
		}
	}

	if (isGood) cout << "GOOD";
	else cout << "BAD" <<" "  << badcount;


	return 0;
}