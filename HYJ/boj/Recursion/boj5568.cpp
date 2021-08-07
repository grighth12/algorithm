#include <iostream>
#include <vector>
#include <set>
#include <stack>
using namespace std;


set<int> s;
int n, k;
vector<int> nums;
vector<bool> checks;

int make_num(int left_num, int right_num) {
	stack<int> st;

	int result = left_num;
	int temp = right_num;

	while (temp != 0) {
		st.push(temp % 10);
		temp /= 10;
	}

	while (!st.empty()) {
		result *= 10;
		result += st.top();
		st.pop();
	}

	return result;
}

void DFS(int num, int count) {
	// 출력한다.
	if (count == k) {
		s.insert(num);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!checks[i]) {
			checks[i] = true;
			int result = make_num(num, nums[i]);
			DFS(result, count + 1);
			checks[i] = false;
		}
	}
	return;
}


int main() {
	cin >> n;
	nums = vector<int>(n, 0);
	checks = vector<bool>(n, false);

	cin >> k;

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	for (int i = 0; i < n; i++) {
		checks[i] = true;
		DFS(nums[i], 1);
		checks[i] = false;
	}

	cout << s.size() << "\n";

	return 0;

}