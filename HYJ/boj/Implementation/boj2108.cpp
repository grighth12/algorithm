#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

double calculate_average(vector<int> v, int N) {
	long long sum = 0;
	double average = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
	}
	average = floor((double)sum / N + 0.5);
	return average;
}

int middle(vector<int> v, int N) {
	int mid = N / 2;

	return v[mid];
}

int alot(map<int, int> m) {
	vector<int> v;
	int count = 0;
	for (auto iter : m) {
		if (iter.second > count) {
			count = iter.second;
		}
	}

	for (auto iter : m) {
		if (iter.second == count) {
			v.push_back(iter.first);
		}
	}

	if (v.size() == 1) {
		return v[0];
	}
	else {
		sort(v.begin(), v.end());
		return v[1];
	}
}

int range(vector<int> v) {
	return v[v.size() - 1] - v[0];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	map<int, int> map1;

	int N;
	cin >> N;
	vector<int> v(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
		if (map1.find(v[i]) != map1.end()) {
			map1[v[i]]++;
		}
		else {
			map1.insert(make_pair(v[i], 1));
		}
	}

	sort(v.begin(), v.end());
	cout << calculate_average(v, N) << "\n";
	cout << middle(v, N) << "\n";
	cout << alot(map1) << "\n";
	cout << range(v) << "\n";

	return 0;
}