#include <vector>
#include <iostream>

using namespace std;

int N, M;

void DFS(vector<int> v)
{
	// ���� üũ�� ������ M�̶� ������, ������ش�.
	if (v.size() == M) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";

		return;
	}
	//������ ��������

	for (int i = 1; i <= N; i++) {
		vector<int> v1 = v;
		v1.push_back(i);
		DFS(v1);
	}	
}

int main() {

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		vector<int> v;
		v.push_back(i);
		DFS(v);
	}
}