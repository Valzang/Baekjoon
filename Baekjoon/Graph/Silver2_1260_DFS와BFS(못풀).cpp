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
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> vertex;

void DFS(int N, int start)
{
	bool check[1001];
	int idx = 1;
	int V = start;

	check[V] = false;
	

	stack<int> idxStack;

	idxStack.push(V);


	while (!idxStack.empty())	
	{
		V = idxStack.top();
		idxStack.pop();
		cout << V << " ";

		for (int i = (int)vertex[V].size() - 1; i >= 0 ; --i)
		{
			int temp = vertex[V][i];
			if (check[temp])
			{
				check[temp] = false;
				idxStack.push(temp);
				//cout << temp << " ";
			}
		}
	}
	cout << '\n';
}

void BFS(int N, int start)
{
	bool check[1001];
	int idx = 0;
	int V = start;

	check[V] = false;
	cout << V << " ";

	queue<int> indexQueue;
	indexQueue.push(start);

	while (!indexQueue.empty())
	{
		V = indexQueue.front();
		indexQueue.pop();
		for (int i = 0; i < (int)vertex[V].size(); ++i)
		{
			if (check[vertex[V][i]])
			{
				indexQueue.push(vertex[V][i]);
				check[vertex[V][i]] = false;
				cout << vertex[V][i] << " ";
			}
		}
	}
	cout << '\n';
}

int main()
{
	int N, M, V;
	
	cin >> N >> M >> V;

	vertex.resize(N + 1);

	for (int i = 0; i < M; ++i)
	{
		int index, v;
		cin >> index >> v;
		vertex[index].push_back(v);
		vertex[v].push_back(index);
		
		sort(vertex[index].begin(), vertex[index].end());
		sort(vertex[v].begin(), vertex[v].end());
	}

	DFS(N, V);
	BFS(N, V);

	return 0;
}