/*

문제
	알고스팟 운영진이 모두 미로에 갇혔다. 미로는 N*M 크기이며, 총 1*1크기의 방으로 이루어져 있다. 
	미로는 빈 방 또는 벽으로 이루어져 있고, 빈 방은 자유롭게 다닐 수 있지만, 벽은 부수지 않으면 이동할 수 없다.
	
	어떤 방에서 이동할 수 있는 방은 상하좌우로 인접한 빈 방이다. 
	즉, 현재 운영진이 (x, y)에 있을 때, 이동할 수 있는 방은 (x+1, y), (x, y+1), (x-1, y), (x, y-1) 이다. 
	단, 미로의 밖으로 이동 할 수는 없다.
	
	벽은 평소에는 이동할 수 없지만, 부수어 버릴 수 있다. 
	벽을 부수면, 빈 방과 동일한 방으로 변한다.

	현재 (1, 1)에 있는 알고스팟 운영진이 (N, M)으로 이동하려면 
	벽을 최소 몇 개 부수어야 하는지 구하는 프로그램을 작성하시오.

입력
	첫째 줄에 미로의 크기를 나타내는 가로 크기 M, 세로 크기 N (1 ≤ N, M ≤ 100)이 주어진다. 
	다음 N개의 줄에는 미로의 상태를 나타내는 숫자 0과 1이 주어진다.
	
	0은 빈 방을 의미하고, 1은 벽을 의미한다.
	
	(1, 1)과 (N, M)은 항상 뚫려있다.

출력
	첫째 줄에 알고스팟 운영진이 (N, M)으로 이동하기 위해 벽을 최소 몇 개 부수어야 하는지 출력한다.

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