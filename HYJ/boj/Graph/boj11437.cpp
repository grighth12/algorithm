#include <iostream>
#include <vector>
#include <cmath>

#define swap(a,b) {int t = a; a=b; b = t;}
#define MAX_NODE 100001

using namespace std;

// depth : ����� ����(����)
// ac[x][y] :: x�� 2^y��° ������ �ǹ�
int depth[MAX_NODE];
int ac[MAX_NODE][20];

vector<int> graph[MAX_NODE];

int max_level;

// DP(ac)�迭�� ����� ����
void getTree(int here, int parent) {
	// here�� ���̴� �θ������  + 1
	depth[here] = depth[parent] + 1;

	// here�� 1��° ������ �θ���
	// here�� 2^0 ��° ���� = parent
	ac[here][0] = parent;

	//MAX_NODE�� log2�� ������ ������ ���ش�.
	// ���Ѽ��� �����ֱ� ���ؼ�
	max_level = (int)floor(log2(MAX_NODE));

	for (int i = 1; i <= max_level; i++) {

		// tmp :: here�� 2^(i-1)��° ����
		/*
		 ��, ac[here][i] = ac[tmp][i-1]��
		 here�� 2^i��° ������ tmp�� 2^(i-1)��° ������ 2^(i-1)��° ����� ���ٴ� �ǹ�
		 ���� �� i = 3�϶�
		 here�� 8��° ������ tmp(here�� 4��° ����)�� 4��° ����� ����.
		 i = 4�϶� here�� 16��° ������ here�� 8��° ����(tmp)�� 8��°�� ����.
		*/

		int tmp = ac[here][i - 1];
		ac[here][i] = ac[tmp][i - 1];
	}

	// dfs �˰���
	int len = graph[here].size();
	for (int i = 0; i < len; i++) {
		int there = graph[here][i];
		if (there != parent)
			getTree(there, here);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;

	cin >> N;

	// ����� �׷����� ����
	for (int i = 1; i < N; i++) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);

	}

	// make_tree�� 1,0�� ���� ������ 0�� -1�� ����
	depth[0] = -1;

	// ��Ʈ ����� 1�� ������ Ʈ���� �����Ѵ�.
	getTree(1, 0);

	cin >> M;

	while (M--) {
		int a, b;
		cin >> a >> b;

		if (depth[a] != depth[b]) {
			// depth[b] >= depth[a]�� �ǵ��� swap
			if (depth[a] > depth[b])
				swap(a, b);

			// b�� �÷��� depth�� �����ش�.
			/*
				�̷����ϸ� ���� max_level�� 4���
				2^4- >2^3 ->2^2 -> 2^1 -> 2^0 ������� ã�ư��ٵ�
				�ᱹ 1, 2,3 ,4, 5...., 31���� ��� ã�� ��İ� ��������.
				������, i�� 4�϶��� 1�� �� �����ߴ� ġ��
				depth[a] <= depth[ac[b][4]]�� ����
				b = ac[b][4];�� �Ǿ� b�� b�� 16��° ������ ���� ���� ���̰�
				depth[a] <= depth[ac[b][1]]�� ����(���� b�� ó�� b�� 16��° ������ b�� �ٲ����.)
				b = ac[b][1];�� �Ǿ� b�� b�� 2��° ������ ���� �ȴ�.
				��, b�� 16��° ������ 2��° ������ ���� ���̴� b�� 18��° ������ ���� �ȴ�.
				(�ϰ��� �ϴ� ���� 3��°, 7����, 11��° �̷� ����鵵 ��� �� �� �ִٴ� �ǹ��̴�.)
			*/

			for (int i = max_level; i >= 0; i--) {
				// b�� 2^i��° ������ a�� depth���� ũ�ų� ������ ��� ������ Ÿ����.
				if (depth[a] <= depth[ac[b][i]])
					b = ac[b][i];
			}
		}
		
		int lca = a;
		

		// a�� b�� �ٸ��ٸ� ���� ���̰� ������
		// ���̸� ��� �÷� ���� �ٸ� ����� ������ ������ ������ �ݺ��Ѵ�.
		// �� , ���� �ٸ� ���(2,3)�� ������ 1�� ���ٸ� lca = ac[2][0]�� ���� 2�� ������ 1���� �� �� �ְ�
		// ���������� ac[3][0] ���� 3�� ������ 1���� �˰ԵǸ� �˰����� ���̳���.

		if (a != b) {
			for (int i = max_level; i >= 0; i--) {
				if (ac[a][i] != ac[b][i]) {
					a = ac[a][i];
					b = ac[b][i];
				}
				lca = ac[a][i];
			}
		}

		cout << lca <<"\n";
	}

	
	return 0;

}