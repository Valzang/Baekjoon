/*

����
	�˰��� ����� ��� �̷ο� ������. �̷δ� N*M ũ���̸�, �� 1*1ũ���� ������ �̷���� �ִ�. 
	�̷δ� �� �� �Ǵ� ������ �̷���� �ְ�, �� ���� �����Ӱ� �ٴ� �� ������, ���� �μ��� ������ �̵��� �� ����.
	
	� �濡�� �̵��� �� �ִ� ���� �����¿�� ������ �� ���̴�. 
	��, ���� ����� (x, y)�� ���� ��, �̵��� �� �ִ� ���� (x+1, y), (x, y+1), (x-1, y), (x, y-1) �̴�. 
	��, �̷��� ������ �̵� �� ���� ����.
	
	���� ��ҿ��� �̵��� �� ������, �μ��� ���� �� �ִ�. 
	���� �μ���, �� ��� ������ ������ ���Ѵ�.

	���� (1, 1)�� �ִ� �˰��� ����� (N, M)���� �̵��Ϸ��� 
	���� �ּ� �� �� �μ���� �ϴ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
	ù° �ٿ� �̷��� ũ�⸦ ��Ÿ���� ���� ũ�� M, ���� ũ�� N (1 �� N, M �� 100)�� �־�����. 
	���� N���� �ٿ��� �̷��� ���¸� ��Ÿ���� ���� 0�� 1�� �־�����.
	
	0�� �� ���� �ǹ��ϰ�, 1�� ���� �ǹ��Ѵ�.
	
	(1, 1)�� (N, M)�� �׻� �շ��ִ�.

���
	ù° �ٿ� �˰��� ����� (N, M)���� �̵��ϱ� ���� ���� �ּ� �� �� �μ���� �ϴ��� ����Ѵ�.

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int result = 10000;
vector<vector<int>> room;
vector<vector<int>> roomCount;

queue<pair<int, int>> indexQueue;

void Recursion()
{
	while (!indexQueue.empty())
	{
		int i = indexQueue.front().first;
		int j = indexQueue.front().second;
		indexQueue.pop();
		if (i < M)
		{
			int temp = room[i + 1][j] == 1 ? roomCount[i][j] + 1 : roomCount[i][j];
			if (roomCount[i + 1][j] > temp)
			{
				roomCount[i + 1][j] = temp;
				indexQueue.push(make_pair(i + 1, j));
			}
		}
		if (j < N)
		{
			int temp = room[i][j + 1] == 1 ? roomCount[i][j] + 1 : roomCount[i][j];
			if (roomCount[i][j + 1] > temp)
			{
				roomCount[i][j + 1] = temp;
				indexQueue.push(make_pair(i, j + 1));
			}
		}
		if (j > 1)
		{
			int temp = room[i][j - 1] == 1 ? roomCount[i][j] + 1 : roomCount[i][j];
			if (roomCount[i][j - 1] > temp)
			{
				roomCount[i][j - 1] = temp;
				indexQueue.push(make_pair(i, j - 1));
			}
		}
		if (i > 1)
		{
			int temp = room[i - 1][j] == 1 ? roomCount[i][j] + 1 : roomCount[i][j];
			if (roomCount[i - 1][j] > temp)
			{
				roomCount[i - 1][j] = temp;
				indexQueue.push(make_pair(i - 1, j));
			}
		}		
	}
}



int main()
{
	cin >> N >> M;
	indexQueue.push(make_pair(1, 1));

	room.resize((size_t)M + 1);
	roomCount.resize((size_t)M + 1);

	for (int i = 1; i <= M; ++i)
	{
		room[i].resize((size_t)N+1);
		roomCount[i].resize((size_t)N + 1);
		string temp;
		cin >> temp;
		for (int j = 1; j <= N; ++j)
		{
			roomCount[i][j] = 10000;
			room[i][j] = temp[j-1] - '0';
		}
	}
	roomCount[1][1] = 0;

	Recursion();

	cout << roomCount[M][N];

	return 0;
}