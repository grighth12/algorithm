#include <vector>
#include <iostream>

using namespace std;

int main() {
	long long A, B, V;

	cin >> A >> B >> V;


	long long last_length = V - A;
	long long step = A - B;

	long long time;
	
	if (last_length / step == 0) {
		time = 1;
	}
	else {
		time = last_length / step;
	}

	cout << time + 1;

	return 0;
}