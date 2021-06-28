#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct User {
	int age;
	string name;
	int order;

	User(int age, string name, int order) {
		this->age = age;
		this->name = name;
		this->order = order;
	}
};

bool cmp(User a, User b) {
	if (a.age < b.age) return true;
	else if (a.age > b.age) return false;
	else {
		return a.order <= b.order;
	}
}



int main() {
	int N;
	cin >> N;
	vector<User> v;

	for (int i = 0; i < N; i++) {
		int age;
		string name;

		cin >> age >> name;

		v.push_back(User(age, name, i));
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < N; i++) {
		cout << v[i].age << " " << v[i].name << "\n";
	}


	return 0;
}