#include <iostream>
#include <vector>

using namespace std;

/*
¹Ý·Ê

911
4564564
91
-> No¿©¾ßµÇ´Âµ¥ YES¶ä

*/

bool isYes = true;

class Trie {
private:
	bool isEnd = false;
	bool ispathway = false;
	Trie* nodes[10];

public:

	Trie() {
		for (int i = 0; i < 10; i++) {
			nodes[i] = nullptr;
		}
	}

	int char_to_number(char ch) {
		return ch - '0';
	}

	void add(int index, string numbers) {
		
		if (isEnd) {
			isYes = false;
		}

		if (index == numbers.size()) {
			isEnd = true;
			if (ispathway) {
				isYes = false;
			}
			return;
		}
		int number = char_to_number(numbers[index]);

		if (nodes[number] == nullptr) {
			nodes[number] = new Trie();
		}

		ispathway = true;

		nodes[number]->add(index + 1, numbers);
	}
	
	bool isFind(int index, string num) {
		if (index == num.size()) {
			return isEnd == true;
		} else{
			int i = num[index] - '0';
			if (nodes[i] == nullptr) {
				return false;
			}
			else {
				return nodes[i]->isFind(index + 1, num);
			}
		}		
	}

	~Trie() {
		for (int i = 0; i < 10; i++) {
			delete nodes[i];
		}
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;
		Trie trie;
		isYes = true;
		for (int i = 0; i < N; i++) {
			string num;
			cin >> num;
			trie.add(0, num);

		}

		if (!isYes)
		{
			cout << "NO" << "\n";
		}
		else {
			cout << "YES" << "\n";
		}
	}
	return 0;
}