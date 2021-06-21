#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int x, y, w, h;

	cin >> x >> y >> w >> h;

	int m = INT_MAX;
	m = min(x, y);
	m = min(m, w - x);
	m = min(m, h - y);

	cout << m;
}