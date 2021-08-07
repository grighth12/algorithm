#include <iostream>

using namespace std;

class MinHeap {
	long long a[100004] = { 0 };
	int last = 0;

public:
	void push(long long x) {
		a[++last] = x;
		int index = last;
		int parent = last / 2;
		while (parent != 0 && a[index] < a[parent]) {
			long long temp = a[index];
			a[index] = a[parent];
			a[parent] = temp;
			index /= 2;
			parent /= 2;
		}
	}

	long long pop() {
		if (last == 0) {
			return 0;
		}
		long long top = a[1];

		a[1] = a[last];
		a[last] = 0;
		last--;

		int currentPos = 1;
		while (true) {
			int leftPos = currentPos * 2;
			int rightPos = currentPos * 2 + 1;

			if (leftPos > last) {
				break;
			}

			long long minValue = a[leftPos];
			int minPos = leftPos;

			if (rightPos <= last && minValue > a[rightPos]) {
				minValue = a[rightPos];
				minPos = rightPos;
			}

			if (a[currentPos] > minValue) {
				long long temp = a[currentPos];
				a[currentPos] = minValue;
				a[minPos] = temp;
				currentPos = minPos;
			}
			else {
				break;
			}

		}

		return top;
	}

};


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;

	cin >> N;

	MinHeap mh;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;

		if (a == 0) {
			cout << mh.pop() << "\n";
		}
		else {
			mh.push(a);
		}
	}

	return 0;
}