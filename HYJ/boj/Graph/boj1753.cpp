#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 2000000000
struct node {
	int id;
	int cost;

	node(int id, int cost) {
		this->id = id;
		this->cost = cost;
	}
};
struct compare {
	bool operator()(node a, node b) {
		return a.cost > b.cost;
	}
};

vector<int> dist;
vector<vector<node>> adjList;
priority_queue<node, vector<node>, compare> pq;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int V, E;
	cin >> V >> E;

	adjList = vector <vector<node>>(V + 1, vector<node>());

	dist = vector<int>(V + 1, 0);
	for (int i = 0; i <= V; i++) {
		dist[i] = MAX;
	}

	int init;
	cin >> init;

	dist[init] = 0;

	for (int i = 0; i < E; i++) {
		int u, v, w;

		cin >> u >> v >> w;
		adjList[u].push_back(node(v, w));
	}

	pq.push(node(init, 0));

	while (!pq.empty()) {
		node now = pq.top();
		
		pq.pop();

		
		// �� ū ����ġ�� ������ ���contine
		if (now.cost > dist[now.id]) continue;

		// ��������Ʈ(����) Ȯ���ؼ� �ּڰ��� ��� �����ϰ� PQ�� �ֱ�
		int len = adjList[now.id].size();
		for (int i = 0; i < len; i++) {
			// ������ �ĺ����� �̱�
			node next = adjList[now.id][i];

			if (dist[next.id] > now.cost + next.cost) {
				dist[next.id] = now.cost + next.cost;
				pq.push(node(next.id, dist[next.id]));
			}
		}
	}


	for (int i = 1; i <= V; i++) {
		if (dist[i] == MAX) {
			cout << "INF\n";
		}
		else {
			cout << dist[i] << "\n";
		}
	}
	return 0;
}