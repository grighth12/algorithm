#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	
	cin >> N;

	set<int> set;
	vector<int> datas(N, 0);
	map<int, int> m;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		set.insert(a);
		datas[i] = a;
	}

	vector<int> v;

	for (auto iter = set.begin(); iter != set.end(); iter++) {
		v.push_back(*iter);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		m.insert(make_pair(v[i], i));
	}

	for (int i = 0; i < datas.size(); i++) {
		cout << m[datas[i]] << " ";
	}



	return 0;
}