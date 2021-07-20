#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long X, Y;

	cin >> X >> Y;

	long long Z = (Y * 100) / X;
	long long right = X;
	long long left = 0;
	long long result = -1;

	if (Z >= 99) {
		cout << -1 << "\n";
		return 0;
	}

	while(left <= right)
	{
		long long mid = (left + right) / 2;
		
		long long currentZ = ((Y + mid) * 100) / (X + mid);

		if (currentZ <= Z) {
			left = mid + 1;
			result = mid + 1;
		}
		else if (currentZ > Z) {
			right = mid - 1;
		}
	}

	cout << result;
	return 0;
}