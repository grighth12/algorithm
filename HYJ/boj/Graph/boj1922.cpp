#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct edge {
	int start;
	int end;
	int cost;

	edge(int start, int end, int cost) {
		this->start = start;
		this->end = end;
		this->cost = cost;
	}
};

struct compare
{
	bool operator()(edge& A, edge& B){
		return A.cost > B.cost;
	}
};

vector<int> parent;
priority_queue<edge, vector<edge>, compare> edges;

int Find(int a) {
	if (parent[a] == a) return a;
	else {
		return parent[a] = Find(parent[a]);
	}
}

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

	// parent √ ±‚»≠
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}


	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		edges.push(edge(a, b, c));
	}
	int sum_cost = 0;
	int cnt = 0;
	while (!edges.empty()) {
		edge now = edges.top();
		edges.pop();


		if (cnt == N - 1) break;

		if (Find(now.start) == Find(now.end)) {

		}
		else {
			Union(now.start, now.end);
			sum_cost += now.cost;
			cnt++;
		}
	}

	cout << sum_cost;
	return 0;
}