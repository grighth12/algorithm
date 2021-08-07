#include <iostream>
#include <vector>

using namespace std;



class IndexTree {
	
	long long S;

public :
	vector<long long> v;
	IndexTree(long long S) {
		v = vector<long long>(2 * S, 0);
		this->S = S;
	}
	IndexTree() {

	}

	// Init
	void Init(vector<long long> nums) {

		// leaf 값 설정
		for (int i = 0; i < nums.size(); i++) {
			v[S + i] = nums[i];
		}

		//내부 노드 값 설정
		for (int i = S - 1; i >= 1; i--) {
			v[i] = v[2 * i] + v[2 * i + 1];
		}
	}

	// Query
	long long Query(long long left, long long right, long long node, long long query_left, long long query_right) {
		// 1. 관련이 아예 없음 
		if (query_right < left || query_left > right) return 0;
		// 2. 관련이 있음
		else if (query_left <= left && right <= query_right) {
			return v[node];
		}
		else {
			long long mid = (left + right) / 2;
			return Query(left, mid, 2 * node, query_left, query_right) +
				Query(mid + 1, right, 2 * node + 1, query_left, query_right);
		}
		// 3. 걸쳐져 있지만, 포함하지 않음.
	}


	// Update
	void Update(long long left, long long right, long long node, long long target, long long dif) {
		
		
		// 1.연관 있음
		if (left <= target && target <= right) {
			v[node] += dif;
			if (left != right) {
				long long mid = (left + right) / 2;
				Update(left, mid, 2 * node, target, dif);
				Update(mid + 1, right, 2 * node + 1, target, dif);
			}
		}
		// 2. 연관 없음
		else {
			return;
		}
	}

	void printTree() {
		for (int i = 1; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
	}

};

int main() {
	int N, M, K;

	cin >> N >> M >> K;
	vector<long long> nums;
	for (int i = 0; i < N; i++) {
		long long temp;
		cin >> temp;
		nums.push_back(temp);
	}
	// S를 구하기
	long long S = 1;

	while (N > S) {
		S *= 2;
	}

	IndexTree t(S);

	// 트리 초기화
	t.Init(nums);
	//t.printTree();

	for (int i = 0; i < M + K; i++) {
		long long a, b, c;
		cin >> a >> b >> c;

		if(a == 1){
			long long temp = t.v[S + b - 1];
			long long dif = c - temp;
			t.Update(1, S, 1, b, dif);
		}
		else if (a == 2) {
			cout << t.Query(1, S, 1, b, c) << "\n";
		}
		//t.printTree();
	}
	return 0;
}