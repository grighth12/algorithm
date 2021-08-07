#include <iostream>

using namespace std;

class MinHeap {
	int a[100000] = { 0 };
	int last = 0;

public : 
	void push(int x) {
		a[++last] = x;
		int index = last;
		while (index != 1 && a[index] <= a[index / 2]) {
			int temp = a[index];
			a[index] = a[index / 2];
			a[index / 2] = temp;
			index /= 2;
		}
	}

	int pop() {

		if (last == 0) {
			return 0;
		}
		int top = a[1];

		a[1] = a[last];
		last--;

		int currentPos = 1;
		while (true) {
			int leftPos = currentPos * 2;
			int rightPos = currentPos * 2 + 1;

			if (leftPos >= last) {
				break;
			}

			int minValue = a[leftPos];
			int minPos = leftPos;

			if (rightPos < last && minValue > a[rightPos]) {
				minValue = a[rightPos];
				minPos = rightPos;
			}

			if (a[currentPos] > minValue) {
				int temp = a[currentPos];
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