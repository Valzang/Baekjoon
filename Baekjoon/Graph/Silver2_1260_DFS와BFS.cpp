/*

����
	�׷����� DFS�� Ž���� ����� BFS�� Ž���� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 
	��, �湮�� �� �ִ� ������ ���� ���� ��쿡�� ���� ��ȣ�� ���� ���� ���� �湮�ϰ�, �� �̻� �湮�� �� �ִ� ���� ���� ��� �����Ѵ�. 
	���� ��ȣ�� 1������ N�������̴�.

�Է�
	ù° �ٿ� ������ ���� N(1 �� N �� 1,000), ������ ���� M(1 �� M �� 10,000), Ž���� ������ ������ ��ȣ V�� �־�����. 
	���� M���� �ٿ��� ������ �����ϴ� �� ������ ��ȣ�� �־�����. 
	� �� ���� ���̿� ���� ���� ������ ���� �� �ִ�. 
	�Է����� �־����� ������ ������̴�.

���
	ù° �ٿ� DFS�� ������ �����, �� ���� �ٿ��� BFS�� ������ ����� ����Ѵ�. 
	V���� �湮�� ���� ������� ����ϸ� �ȴ�.

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, V;

vector<vector<bool>> connection;

void DFS(vector<bool> &check, int start)
{
	check[start] = true;
	cout << start << " ";
	for (int i = 1; i <= N; ++i)
	{
		if (check[i] || !connection[start][i])
			continue;
		DFS(check, i);
	}
}

void BFS(vector<bool> check, queue<int> idxQueue)
{
	int start = idxQueue.front();
	idxQueue.pop();

	if (!check[start])
	{
		check[start] = true;
		cout << start << " ";
	}

	for (int i = 1; i <= N; ++i)
	{
		if (check[i] || !connection[start][i])
			continue;
		cout << i << " ";
		check[i] = true;
		idxQueue.push(i);
	}
	if(!idxQueue.empty())
		BFS(check, idxQueue);
}


int main()
{

	vector<bool> check;
	cin >> N >> M >> V;

	connection.resize(N+1);
	for (int i = 1; i <= N; ++i)
		connection[i].resize(N + 1);

	check.resize(N + 1);
	
	for (int i = 0; i < M; ++i)
	{
		int start = 0, end = 0;
		cin >> start >> end;
		connection[start][end] = true;
		connection[end][start] = true;
	}

	DFS(check, V);
	cout << '\n';
	check.assign(N+1, false);
	queue<int> idx;
	idx.push(V);

	BFS(check, idx);

	return 0;
}