#include <iostream>
using namespace std;

int main() {
	int index = 0;
	int N;
	int number = 0;
	int step = 0;
	cin >> N;

	while (index < N) {
		step++;
		int temp = step;
		int count = 0;
		while (temp != 0) {
			if (temp % 10 == 6) {
				count++;
				if (count == 3) {
					number = step;
					index++;
					count = 0;
					break;
				}
			}
			else {
				count = 0;
			}
			temp /= 10;
		}
	}

	cout << number;
}