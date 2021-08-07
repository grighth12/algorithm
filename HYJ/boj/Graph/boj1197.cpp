#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> parent;


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

struct compare {
	bool operator()(edge a, edge b) {
		return a.cost > b.cost;
	}
};

int Find(int a) {
	if (parent[a] == a) return a;
	else {
		return parent[a] = Find(parent[a]);
	}
}

void Union(int a, int b) {
	int pa = parent[a];
	int pb = parent[b];

	parent[pb] = pa;
}

priority_queue < edge, vector<edge>, compare> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int V, E;

	cin >> V >> E;

	parent = vector<int>(V + 1);

	// 부모 노드 초기화
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < E; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		pq.push(edge(A, B, C));
	}

	int cnt = 0;
	int sum = 0;
	while (!pq.empty()) {
		edge now = pq.top();
		pq.pop();

		//최소 신장트리의 간선의 개수는 V-1개임
		if (cnt == V - 1) break;
		
		if (Find(now.start) == Find(now.end)) {
			continue;
		}
		else {
			Union(now.start, now.end);
			cnt++;
			sum += now.cost;
		}

	}


	cout << sum << "\n";

	return 0;
}