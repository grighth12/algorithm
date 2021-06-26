#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	bool isNumber = false;
	int answer = 0;
	for (int i = 0; i < N; i++) {
		int sum = 0;
		int temp = i;
		sum += temp;
		while (temp > 0) {
			sum += temp % 10;
			temp /= 10;
		}

		if (sum == N) {
			answer =  i;
			isNumber = true;
			break;
		}
	}

	if (isNumber) {
		cout << answer;
	}
	else {
		cout << 0;
	}
	return 0;
}