#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	
	cin >> N >> M;
	vector<bool> v(11, false);

	for (int i = 0; i < M; i++) {
		int temp;
		cin >> temp;
		v[temp] = true;
	}

	int min_count = abs(N - 100);

	// 0~500000탐색하면서 버튼 탐색
	for (int i = 0; i <= 1000002; i++) {
		// temp 가 0일 떄는 while문을 거치지 않는다.. (예외)
		int temp = i;
		bool isPossible = true;
		int button_count = 0;
		// 문제 -> 0 일때 while문에 들어가야되는데. 못들어감.
		// 10일 때 1, 0 두개를 탐색해야되는데. 그러지 못함.
		/*
		while (temp != 0) {
			button_count++;
			int na = temp % 10;
			if (v[na]) {
				isPossible = false;
				break;
			}
			temp /= 10;
		}*/

		do {
			button_count++;
			int na = temp % 10;
			if (v[na]) {
				isPossible = false;
				break;
			}
			temp /= 10;
		} while (temp != 0);


		//만약 가능하다면 (리모컨 이동이)
		// 숫자를 입력해서 이동한 숫자와 목표 채널까지의 차이(+,-)를 구한다.
		if (isPossible) {
			min_count = min(min_count, abs(N - i) + button_count);
		}
		
		
	}
	
	cout << min_count;

	return 0;
}