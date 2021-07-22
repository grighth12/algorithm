#include <iostream>
#include <vector>

using namespace std;

class Tree {
	vector<vector<char>> v;
public:
	Tree() {
		v = vector<vector<char>>(26, vector<char>(2, '.'));
	}

	void push(char parent, char left, char right) {		
		int index = parent - 'A';

		// left
		v[index][0] = left;
		v[index][1] = right;
	}

	void preOrder(int index) {
		char left = v[index][0];
		char right = v[index][1];
		char now = index + 'A';

		if (now != '.')
		{
			cout << now;
		}
		
		if(left != '.')  preOrder(left - 'A');
		if(right != '.') preOrder(right - 'A');
		
	}


	void inOrder(int index) {
		char left = v[index][0];
		char right = v[index][1];
		char now = index + 'A';


		if(left !='.') inOrder(left - 'A');
		if(now !='.') cout << now;
		if(right !='.') inOrder(right - 'A');

	}

	void postOrder(int index) {
		char left = v[index][0];
		char right = v[index][1];
		char now = index + 'A';



		if(left != '.') postOrder(left - 'A');
		if(right != '.') postOrder(right - 'A');
		if(now != '.') cout << now;
		

	}
};

int main() {
	int N;
	cin >> N;
	Tree t;
	for (int i = 0; i < N; i++) {
		char parent, left, right;
		cin >> parent >> left >> right;
		t.push(parent, left, right);
	}

	t.preOrder(0); 
	cout << "\n";
	t.inOrder(0); 
	cout << "\n";
	t.postOrder(0);

	return 0;
}