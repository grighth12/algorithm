#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


// L���̸� ���,
// �ּ� �Ѱ��� ���� , �ּ� �� ���� �������� ������.
// ��ȣ�� ���ĵ� ���ڿ���.

int L, C;
vector<char> alpha;


bool isVowel(char ch) {
	return ch == 'a' || ch == 'i' || ch == 'u' || ch == 'e' || ch == 'o';
}

void DFS(int index, int vowel, int consonant, string str) {
	
	// �������ΰ�?
	if (vowel + consonant == L) {
		if (vowel >= 1 && consonant >= 2) {
			cout << str << "\n";
		}
		return;
	}

	for (int i = index + 1; i < C; i++) {
		if (isVowel(alpha[i])) DFS(i, vowel + 1, consonant, str + alpha[i]);
		else DFS(i, vowel, consonant + 1, str + alpha[i]);
	}
	// üũ��
	// �� �� �ִ°�?
	// �湮�� �� �ִ°�?
	// �湮
	// üũ�ƿ�

}

int main() {
	cin >> L >> C;

	alpha = vector<char>(C);

	for (int i = 0; i < C; i++) {
		cin >> alpha[i];
	}

	sort(alpha.begin(), alpha.end());

	// char���� string ���� ��ȯ�ϴ� ��� 
	// string s�� �����
	// s += char�� ���ָ� �ȴ�.
	for (int i = 0; i < C; i++) {
		if (isVowel(alpha[i])) {
			string s;
			s += alpha[i];
			DFS(i, 1, 0, s);
		}
		else {
			string s;
			s += alpha[i];
			DFS(i, 0, 1, s);
		}
	}

	return 0;
}