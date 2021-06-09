#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	map<int, vector<int>> map;
	int length;
	scanf("%d", &length);
	for (int i = 0; i < length; i++) {
		int num1, num2;
		scanf("%d %d", &num1, &num2);
		if(map.count(num1) > 0){
			auto&& connect = map[num1];
			connect.push_back(num2);
			map[num1] = connect;
		}
		else {
			vector<int> connect;
			connect.push_back(num2);
			map.insert(make_pair(num1, connect));
		}
		if (map.count(num2) > 0) {
			auto&& connect = map[num2];
			connect.push_back(num1);
			map[num2] = connect;
		}
		else {
			vector<int> connect;
			connect.push_back(num1);
			map.insert(make_pair(num2, connect));
		}
	}

	vector<int> result;
	result.push_back(1);

	int i = 0;
	while(result.size() > i) {
		if (map.count(result[i]) > 0) {
			for (const auto& value : map[result[i]]) {
				if (find(result.begin(), result.end(), value) == result.end()) {
					result.push_back(value);
				}
			}
		}
		i++;
	}
    
	cout << i-1;

	return 0;
}