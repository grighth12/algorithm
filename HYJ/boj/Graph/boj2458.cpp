#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define MAX 2000000000

using namespace std;

struct Edge {
public :
	long long start;
	long long end;
	long long cost;

	Edge() {

	}

	Edge(long long start, long long end, long long cost) {
		this->start = start;
		this->end = end;
		this->cost = cost;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long N, M;
	cin >> N >> M;

	vector<Edge> edges;
	vector<long long> dist(N + 1, MAX);

	dist[1] = 0;

	for (int i = 0; i < M; i++) {
		long long a, b, c;
		cin >> a >> b >> c;

		edges.push_back(Edge(a, b, c));
	}


	for (int i = 1; i <= N - 1; i++) {
		for (int j = 0; j < M; j++) {
			Edge now = edges[j];


			// 출발지가 현재 무한대이면
			if (dist[now.start] == MAX)
				continue;
			// 최솟값으로 값 갱신 가능하면 갱신
			
			dist[now.end]
				= min(dist[now.end], dist[now.start] + now.cost);
		}
	}

	bool IsAnswer = true;
	for (int i = 0; i < M; i++) {
		Edge now = edges[i];

		if (dist[now.start] == MAX) continue;
		
		if (dist[now.end] > dist[now.start] + now.cost) {
			IsAnswer = false;
			break;
		}
	}

	if (IsAnswer) {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == MAX) {
				cout << "-1" << "\n";
			}
			else {
				cout << dist[i] << "\n";
			}
			
		}
	}
	else {
		cout << "-1\n";
	}

	return 0;
}