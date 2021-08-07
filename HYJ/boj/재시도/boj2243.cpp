#include <iostream>
#include <vector>

using namespace std;

class Tree {
	vector<long long> v;
	long long S;
public:
	Tree(long long S) {
		v = vector<long long>(2 * S, 0);
		this->S = S;
	}

	// 탑다운으로 구현해보자.
	void update(long long target,  long long dif) {
		
		// target을 찾는다.
		long long node = S + target - 1;
		v[node] += dif;
		node /= 2;
		// 부모노드까지 값을 수정한다.

		while (node != 0) {
			v[node] = v[node * 2] + v[node * 2 + 1];
			node /= 2;
		}
		
		
	}

	long long query(long long left, long long right, long long node, long long count) {
		
		/*if (left == right) {
			update(left, -1);
			return left;
		}

		long long answer = 0;
		// 포함되어있는가?
		if (count <= v[node]) {

			long long mid = (left + right) / 2;
			long long left_node = node * 2;
			long long right_node = node * 2 + 1;
			// 왼쪽에 포함되어있는가?
			if (left_node < v.size() && count <= v[left_node]) {
				answer = query(left, mid, left_node, count);
			}
			else if (right_node < v.size() && count <= v[right_node])
			{
				answer = query(mid + 1, right, right_node, count - v[left_node]);
			}
				

		}
		else {
			return 0;
		}*/

		if (left == right) {
			return left;
		}

		long long mid = (left + right) / 2;
		if (v[node * 2] >= count) {
			return query(left, mid, node * 2, count);
		}
		else {
			return query(mid + 1, right, node * 2 + 1, count - v[node * 2]);
		}

	}

	void print() {
		for (int i = 1; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
	}
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N;
	cin >> N;

	long long S = 1;

	while (S < 1000000) {
		S *= 2;
	}


	Tree t(S);

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;

		if (a == 1) {
			long long b;
			
			cin >> b;
			long long answer = t.query(1, N, 1, b);
			cout << answer << "\n";
			t.update(answer, -1);
		}
		else if (a == 2) {
			long long b, c;
			cin >> b >> c;
			t.update(b, c);
			//t.print();
		}
	}

	return 0;
}