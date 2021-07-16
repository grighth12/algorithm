#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int compare(string A, string B) {

	int count = 0;

	for (int i = 0; i < A.length(); i++) {
		if (A[i] != B[i]) count++;
	}

	return count;
}

int sol(string A, string B) {
	int dif = B.length() - A.length();
	int m = 2000000000;
	
	for (int i = 0; i <= dif; i++) {
		m = min(m, compare(A, B.substr(i, A.length())));
	}

	return m;
}

int main() {
	string A, B;

	cin >> A >> B;

	int answer = sol(A, B);

	cout << answer;
	return 0;
}