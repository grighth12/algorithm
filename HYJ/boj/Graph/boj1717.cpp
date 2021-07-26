#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;


int Find(int a) {
	// 현재 자신의 값
	if (a == parent[a]) return a;
	else return parent[a] = Find(parent[a]);
}

//Union
void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);

	parent[pb] = pa;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;

	cin >> N >> M;

	parent = vector<int>(N + 1, 0);

	// 초기화

	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int op, a, b;
		cin >> op >> a >> b;

		if (op == 0) {
			Union(a, b);
		}
		else if(op == 1){
			if (Find(a) == Find(b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}

	return 0;

}