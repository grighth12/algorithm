#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


// L개이면 출력,
// 최소 한개의 모음 , 최소 두 개의 자음으로 구성됨.
// 암호는 정렬된 문자열임.

int L, C;
vector<char> alpha;


bool isVowel(char ch) {
	return ch == 'a' || ch == 'i' || ch == 'u' || ch == 'e' || ch == 'o';
}

void DFS(int index, int vowel, int consonant, string str) {
	
	// 목적지인가?
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
	// 체크인
	// 갈 수 있는가?
	// 방문할 수 있는가?
	// 방문
	// 체크아웃

}

int main() {
	cin >> L >> C;

	alpha = vector<char>(C);

	for (int i = 0; i < C; i++) {
		cin >> alpha[i];
	}

	sort(alpha.begin(), alpha.end());

	// char형을 string 으로 변환하는 방법 
	// string s을 만들고
	// s += char를 해주면 된다.
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